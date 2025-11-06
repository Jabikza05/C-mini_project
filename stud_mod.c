#include"header.h"

void stud_mod(ST **p)
{
    if (*p == NULL)
    {
        printf("No records to modify.\n");
        return;
    }

    char op;

    printf("\n___________________________________________________\n");
    printf("| Enter which record to search for modification      |\n");
    printf("|                                                    |\n");
    printf("|   R/r : to search rollno                           |\n");
    printf("|   N/n : to search name                             |\n");
    printf("|   P/p : percentage  based                          |\n");
    printf("|                                                    |\n");
    printf("-----------------------------------------------------\n");

    scanf(" %c", &op);

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

    temp = head2;

    switch(op)
    {
        case 'R': case 'r':
        {
            int n;
            printf(" Enter the roll no to modify: ");
            scanf("%d", &n);

            while(temp != NULL)
            {
                if(temp->roll == n)
                {
                    printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                            temp->roll, temp->name, temp->marks);

                    printf(" Enter new name: ");
                    scanf("%s", temp->name);

                    printf(" Enter new marks: ");
                    scanf("%f", &temp->marks);

                    printf("Record updated temporary.....\n");
                    break;
                }
                temp = temp->next;
            }
            if(temp == NULL)
                printf("Roll no not found!\n");
            break;
        }

        case 'N': case 'n':
        {
            char s[20];
            printf(" Enter the name: ");
            scanf("%s", s);

            // 🔹 Step 1: show all matching names if duplicates exist
            int found = 0;
            ST *temp2 = head2;
            printf("\nMatching records with name '%s':\n", s);
            printf("--------------------------------------\n");
            printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
            printf("--------------------------------------\n");
            while (temp2)
            {
                if (strcmp(temp2->name, s) == 0)
                {
                    printf("|%-5d |%-20s |%-7.2f|\n", temp2->roll, temp2->name, temp2->marks);
                    printf("--------------------------------------\n");
                    found = 1;
                }
                temp2 = temp2->next;
            }

            if (!found)
            {
                printf("Name not found!\n");
                break;
            }

            // 🔹 Step 2: Ask roll number if duplicates exist
            printf("Enter roll number to modify from above list: ");
            int rollno;
            scanf("%d", &rollno);

            temp = head2;
            while(temp != NULL)
            {
                if(temp->roll == rollno && strcmp(temp->name, s) == 0)
                {
                    printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                            temp->roll, temp->name, temp->marks);

                    printf(" Enter new name: ");
                    scanf("%s", temp->name);

                    printf(" Enter new marks: ");
                    scanf("%f", &temp->marks);

                    printf("Record updated temporary .......\n");
                    break;
                }
                temp = temp->next;
            }
            break;
        }

        case 'P': case 'p':
        {
            float per;
            printf(" Enter the percentage to search: ");
            scanf("%f", &per);

            ST *found = NULL;
            while(temp != NULL)
            {
                if(temp->marks == per)
                {
                    found = temp;
                    break;
                }
                temp = temp->next;
            }

            if(found == NULL)
            {
                printf("Percentage not found!\n");
                break;
            }

            printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                    found->roll, found->name, found->marks);

            printf(" Enter new name: ");
            scanf("%s", found->name);

            printf(" Enter new marks: ");
            scanf("%f", &found->marks);

            printf("Record updated temporary...........\n");
            break;
        }

        default:
            printf("Invalid option!\n");
    }

    // Display updated temporary list
    temp = head2;
    printf("\n--------------------------------------\n");
    printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
    printf("--------------------------------------\n");
    while(temp)
    {
        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
        printf("--------------------------------------\n");
        temp = temp->next;
    }

    // Free temporary list
    while(head2)
    {
        t = head2;
        head2 = head2->next;
        free(t);
    }
}

