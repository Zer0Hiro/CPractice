// Add new object to the end of the list 
void add(struct node *head, struct node *tail, struct node
*new_node )
{
 new_node->next = NULL; //if not done before
 if( head == NULL )
 head = new_node;
 else
 tail->next = new_node;
 tail = new_node;
}

// You can also use structures for linkedlist
typedef struct 
{
    struct Node *head;
    struct Node *tail
} log;

// Possible to create Pointer already in struct
typedef struct list
{
    char *head;
    /* data */
}List, *Plist;
