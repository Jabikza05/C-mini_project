#include"header.h"


void stud_del(ST **p)
{
    if (*p == NULL)
    {
        printf("No records to delete.\n");
        return;
    }

    char op;
    printf("\n________________________________\n");
    printf("|                                |\n");
    printf("| R/r : Enter roll to delete     |\n");
    printf("| N/n : Enter name to delete     |\n");
    printf("|                                |\n");
    printf("----------------------------------\n");
    scanf(" %c", &op);

    // Duplicate the list temporarily
    ST *temp = *p, *head2 = NULL, *new, *t, *last = NULL;

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

    ST *prev = NULL;
    temp = head2;

    switch (op)
    {
        case 'R': case 'r':
        {
            int roll;
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);

            while (temp)
            {
                if (temp->roll == roll)
                {
                    if (prev == NULL)
                        head2 = temp->next;
                    else
                        prev->next = temp->next;

                    free(temp);
                    printf("Record deleted temporarily....\n");
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            break;
        }

        case 'N': case 'n':
        {
            char name[20];
            printf("Enter name to delete: ");
            scanf("%s", name);

            // 🔹 Step 1: show all matching names and count them
            int found = 0, count = 0;
            ST *temp2 = head2;
            printf("\nMatching records with name '%s':\n", name);
            printf("--------------------------------------\n");
            printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
            printf("--------------------------------------\n");
            while (temp2)
            {
                if (strcmp(temp2->name, name) == 0)
                {
                    printf("|%-5d |%-20s |%-7.2f|\n", temp2->roll, temp2->name, temp2->marks);
                    printf("--------------------------------------\n");
                    found = 1;
                    count++;
                }
                temp2 = temp2->next;
            }

            if (!found)
            {
                printf("No records found with the given name.\n");
                break;
            }

            int rno;
            prev = NULL;
            temp = head2;

            // ✅ If only one record with that name → delete directly
            if (count == 1)
            {
                while (temp)
                {
                    if (strcmp(temp->name, name) == 0)
                    {
                        if (prev == NULL)
                            head2 = temp->next;
                        else
                            prev->next = temp->next;

                        free(temp);
                        printf("Record deleted (temporarily) successfully.\n");
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
            }
            else   // ✅ Multiple records → ask roll number
            {
                printf("Enter roll number to delete from above list: ");
                scanf("%d", &rno);

                temp = head2;
                prev = NULL;
                while (temp)
                {
                    if (temp->roll == rno && strcmp(temp->name, name) == 0)
                    {
                        if (prev == NULL)
                            head2 = temp->next;
                        else
                            prev->next = temp->next;

                        free(temp);
                        printf("Record deleted (temporarily) successfully.\n");
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
            }
            break;
        }

        default:
            printf("Invalid option!\n");
            break;
    }

    // Display temporary list in tabular format
    temp = head2;
    printf("\n--------------------------------------\n");
    printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
    printf("------------------------------------\n");
    while (temp)
    {
        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
        printf("------------------------------------\n");
        temp = temp->next;
    }

    // Free temporary list
    while (head2)
    {
        t = head2;
        head2 = head2->next;
        free(t);
    }
}

