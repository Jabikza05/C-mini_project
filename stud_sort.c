#include "header.h"

void stud_sort(ST **ptr)
{
    if (*ptr == NULL || (*ptr)->next == NULL)
    {
        printf("No records found to sort or only one record is entered ....\n");
        return;
    }

    char op;

    printf("\n________________________________\n");
    printf("|                                |\n");
    printf("| N/n : Sort with Name           |\n");
    printf("| P/p : Sort with Percentage     |\n");
    printf("|                                |\n");
    printf("----------------------------------\n");

    scanf(" %c", &op);

    // Duplicate the list temporarily
    ST *temp = *ptr, *head2 = NULL, *new, *last = NULL;
    while (temp)
    {
        new = (ST*)malloc(sizeof(ST));
        *new = *temp;
        new->next = NULL;

        if (head2 == NULL)
            head2 = last = new;
        else
        {
            last->next = new;
            last = new;
        }
        temp = temp->next;
    }

    ST *temp1, *temp2;

    switch (op)
    {
        case 'N': case 'n':
            printf("Do you want to sort with Name ...[Y/y]:");
            scanf(" %c",&op);
            if(op=='Y'||op=='y')
            {
                for (temp1 = head2; temp1 != NULL; temp1 = temp1->next)
                {
                    for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
                    {
                        if (strcmp(temp1->name, temp2->name) > 0)
                        {
                            ST t = *temp1;
                            *temp1 = *temp2;
                            *temp2 = t;

                            ST *swap = temp1->next;
                            temp1->next = temp2->next;
                            temp2->next = swap;
                        }
                    }
                }
            }
            else
            {
                printf("\nSort is not done.\n");
            }
            break;

        case 'P': case 'p':
            printf("Do you want to sort with Percentage ...[Y/y]:");
            scanf(" %c",&op);
            if(op=='Y'||op=='y')
            {
                for (temp1 = head2; temp1 != NULL; temp1 = temp1->next)
                {
                    for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
                    {
                        if (temp1->marks < temp2->marks)
                        {
                            ST t = *temp1;
                            *temp1 = *temp2;
                            *temp2 = t;

                            ST *swap = temp1->next;
                            temp1->next = temp2->next;
                            temp2->next = swap;
                        }
                    }
                }
            }
            else
            {
                printf("\nSort is not done.\n");
            }
            break;

        default:
            printf("Invalid choice for sorting.\n");
            // Free temporary list
            while (head2)
            {
                temp = head2;
                head2 = head2->next;
                free(temp);
            }
            return;
    }

    // Display temporary sorted list in tabular format
    printf("\n--------------------------------------\n");
    printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
    printf("------------------------------------\n");
    temp = head2;
    while (temp)
    {
        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
        printf("------------------------------------\n");
        temp = temp->next;
    }

    // Free temporary list (so main list remains safe)
    while (head2)
    {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }
}
