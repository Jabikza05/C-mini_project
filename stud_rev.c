
#include"header.h"

void stud_rev(ST **p)
{
    if (*p == NULL)
    {
        printf("No records to reverse.\n");
        return;
    }

    // Duplicate list temporarily
    ST *temp = *p, *head2 = NULL, *new, *t, *last = NULL;
    while(temp)
    {
        new = (ST*)malloc(sizeof(ST));
        *new = *temp;
        new->next = NULL;

        if(head2 == NULL)
            head2 = last = new;
        else
        {
            last->next = new;
            last = new;
        }
        temp = temp->next;
    }

    // Reverse the duplicate list (temporary)
    ST *prev = NULL, *next;
    temp = head2;
    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head2 = prev;

    // Display temporary reversed list
    printf("\nRecords in reverse order temporary...:\n");
    printf("\n--------------------------------------\n");
    printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
    printf("------------------------------------\n");
    temp = head2;
    while(temp)
    {
        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
        printf("------------------------------------\n");
        temp = temp->next;
    }

    // Free the temporary list
    while(head2)
    {
        t = head2;
        head2 = head2->next;
        free(t);
    }
}

