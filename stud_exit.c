

#include"header.h"
// Exit function
void stud_exit(ST *p)
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

