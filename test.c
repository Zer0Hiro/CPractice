#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100 
#define NUM_LABS 5          
#define EXAM_WEIGHT 0.85    
#define LAB_WEIGHT 0.15     
#define MIN_PASS_SCORE 55.0  

//define the Student struct
typedef struct {
    char* name;
    long id;
    float exam_score;
    char lab_submissions[NUM_LABS + 1];
    float final_grade;
} Student;

//define the University struct
typedef struct {
    Student* students;
    int num_students;
} University;

void read_students_from_file(University* uni, const char* filename);
void write_students_to_file(University* uni, const char* filename, int option);
void calculate_and_write_final_grades(University* uni, const char* filename);
void add_new_student(University* uni, const char* filename);
void add_bonus(University* uni, const char* filename);
void write_end_of_program(const char* filename);
void free_university(University* uni);

int main() {
    University uni = { NULL, 0 };  //initialize university structure
    int choice = 0, option1_chosen = 0;  // initialize choice var

    while (choice != 6) {
        //display the menu
        printf("\nMenu:\n");
        printf("1. Read students from file\n");
        printf("2. Write students to file\n");
        printf("3. Calculate final grades\n");
        printf("4. Add a new student\n");
        printf("5. Add bonus to a student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //make sure the user is choosing option 1 first
        if (!option1_chosen && choice != 1) {
            printf("Please choose option 1 first to read student data.\n");
            continue;
        }

        //process menu choices
        switch (choice) {
        case 1:
            read_students_from_file(&uni, "input.txt");
            option1_chosen = 1;
            break;
        case 2:
            write_students_to_file(&uni, "output.txt", 2);
            break;
        case 3:
            calculate_and_write_final_grades(&uni, "output.txt");
            break;
        case 4:
            add_new_student(&uni, "output.txt");
            break;
        case 5:
            add_bonus(&uni, "output.txt");
            break;
        case 6:
            write_end_of_program("output.txt");
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    //free dynamically allocated memory
    free_university(&uni);
    return 0;
}

//function to read student data from input file
void read_students_from_file(University* uni, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char name[MAX_NAME_LENGTH];
    long id;
    float exam_score;
    char lab_submissions[NUM_LABS + 1];

    while (fscanf(file, "%s %ld %f %s", name, &id, &exam_score, lab_submissions) == 4) {
        uni->num_students++;
        uni->students = realloc(uni->students, uni->num_students * sizeof(Student));
        if (!uni->students) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        Student* new_student = &uni->students[uni->num_students - 1];
        new_student->name = malloc(strlen(name) + 1);
        if (!new_student->name) {
            printf("Memory allocation failed for student name.\n");
            fclose(file);
            return;
        }
        strcpy(new_student->name, name);
        new_student->id = id;
        new_student->exam_score = exam_score;
        strcpy(new_student->lab_submissions, lab_submissions);
    }

    fclose(file);
    printf("Input accepted.\n");
}

//function to write student data to output file
void write_students_to_file(University* uni, const char* filename, int option) {
    FILE* file = fopen(filename, "a");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "\nOPTION %d:\n", option);
    for (int i = 0; i < uni->num_students; i++) {
        Student* student = &uni->students[i];
        int lab_count = 0;
        for (int j = 0; j < NUM_LABS; j++) {
            if (student->lab_submissions[j] == '1') {
                lab_count++;
            }
        }
        char pass_fail = lab_count >= 3 ? '1' : '0';
        fprintf(file, "Student %d: %s %ld %.2f %c\n", i + 1, student->name, student->id, student->exam_score, pass_fail);
    }

    fclose(file);
    printf("Students data written to %s\n", filename);
}

//function to calc final grades and write to output file
void calculate_and_write_final_grades(University* uni, const char* filename) {
    FILE* file = fopen(filename, "a");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "\nOPTION 3:\nBEFORE:\n");
    for (int i = 0; i < uni->num_students; i++) {
        Student* student = &uni->students[i];
        int lab_count = 0;
        for (int j = 0; j < NUM_LABS; j++) {
            if (student->lab_submissions[j] == '1') {
                lab_count++;
            }
        }
        char pass_fail = lab_count >= 3 ? '1' : '0';
        fprintf(file, "Student %d: %s %ld %.2f %c\n", i + 1, student->name, student->id, student->exam_score, pass_fail);
    }

    fprintf(file, "\nAFTER:\n");
    for (int i = 0; i < uni->num_students; i++) {
        Student* student = &uni->students[i];
        int lab_count = 0;
        for (int j = 0; j < NUM_LABS; j++) {
            if (student->lab_submissions[j] == '1') {
                lab_count++;
            }
        }
        float lab_score = lab_count >= 3 ? 100.0 : 0.0;
        if (student->exam_score < MIN_PASS_SCORE) {
            student->final_grade = student->exam_score;
        }
        else {
            student->final_grade = (student->exam_score * EXAM_WEIGHT) + (lab_score * LAB_WEIGHT);
        }
        fprintf(file, "Student %d: %s %ld %.2f final: %.2f\n", i + 1, student->name, student->id, student->exam_score, student->final_grade);
    }

    fclose(file);
    printf("Final grades calculated and written to %s\n", filename);
}

//function to add a new student
void add_new_student(University* uni, const char* filename) {
    uni->num_students++;
    uni->students = realloc(uni->students, uni->num_students * sizeof(Student));
    if (!uni->students) {
        printf("Memory allocation failed.\n");
        return;
    }

    Student* new_student = &uni->students[uni->num_students - 1];
    char name[MAX_NAME_LENGTH];
    long id;
    float exam_score;
    char lab_submissions[NUM_LABS + 1];

    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter student ID: ");
    scanf("%ld", &id);
    printf("Enter exam score: ");
    scanf("%f", &exam_score);
    printf("Enter lab submissions (5 digits of 0/1): ");
    scanf("%s", lab_submissions);

    new_student->name = malloc(strlen(name) + 1);
    if (!new_student->name) {
        printf("Memory allocation failed for student name.\n");
        return;
    }
    strcpy(new_student->name, name);
    new_student->id = id;
    new_student->exam_score = exam_score;
    strcpy(new_student->lab_submissions, lab_submissions);

    write_students_to_file(uni, filename, 4);
    printf("New student added successfully.\n");
}

//function to add bonus 
void add_bonus(University* uni, const char* filename) {
    char name[MAX_NAME_LENGTH];
    float bonus;
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter bonus points: ");
    scanf("%f", &bonus);

    int found = 0;
    for (int i = 0; i < uni->num_students; i++) {
        Student* student = &uni->students[i];
        if (strcmp(student->name, name) == 0) {
            student->exam_score += bonus;
            if (student->exam_score > 100.0) {
                student->exam_score = 100.0;
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student %s not found.\n", name);
    }
    else {
        write_students_to_file(uni, filename, 5);
        printf("Bonus added successfully.\n");
    }
}

//function to write the end-of-program message and exit
void write_end_of_program(const char* filename) {
    FILE* file = fopen(filename, "a");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "\nOPTION 6:\nEnd Of Program\n");
    fclose(file);
}

//function to free dynamically allocated memory
void free_university(University* uni) {
    for (int i = 0; i < uni->num_students; i++) {
        free(uni->students[i].name);
    }
    free(uni->students);
    uni->students = NULL;
    uni->num_students = 0;
}