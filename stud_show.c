#include"header.h"
void stud_show(ST *p)
{
    if (p == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }
printf("displaying the student record 's in tabular format...\n");

    printf("\n--------------------------------------\n");
    printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
    printf("------------------------------------\n");

    while (p != NULL)
    {
        printf("|%-5d |%-20s |%-7.2f|\n", p->roll, p->name, p->marks);
	printf("------------------------------------\n");
        p = p->next;
    }

    //printf("------------------------------------\n");
}


