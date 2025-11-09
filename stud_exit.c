
#include"header.h"
// Exit function
void stud_exit(ST *p)
{   
    char op;
    printf("Do you want to delete all the Records....[Y/y]:");
	scanf(" %c",&op);
	if(op=='Y'||op=='y')
    {
    printf("\nExiting program. Goodbye!\n");

    // Optional: free memory
    ST *temp;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }

    exit(0); // terminate program
 }

}

