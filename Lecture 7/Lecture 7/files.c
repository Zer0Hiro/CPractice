#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// To create pointer for the file
	FILE* NameOfFile;

	//FOPEN
	NameOfFile = fopen("name.txt", "mode(w,r)"); // Opens file (name.txt) in specific mode
	if (NameOfFile == NULL)
	{
		// What to do if file didn't open
	}
	/* MODE OPTIONS
		r - Read Only
		w - Write (Will erase previous file if already existed)
		a - Append info to already existing fie
		r+ - Read + Write
		w+ - Write + Read (Will erase previous file if already existed)

		// NOT SAFE TO USE
		a+ - Append + Read
	*/

	//FCLOSE
	fclose(NameOfFile); // Will close and save file (Also free some memory)
	
	//				IMPORTANT!!!
	// no need to use fclose() if we use exit()

	//FSCANF
	int num;
	fscanf(NameOfFile, "%d", &num); // Reads info from file and puts it in num
	
	// NOTE
	// Will return fscanf = -1 at the end of file (basically means end of file)

	//FPRINTF
	int input;
	fprintf(NameOfFile, "%TypeOfFile", input); // Prints input inside the file

}