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
    while (temp)
    {
        new = (ST *)malloc(sizeof(ST));
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

    temp = head2;

    switch(op)
    {
        case 'R': case 'r':
        {
            printf("Do you want to perform modification based on roll number [Y/y]: ");
            scanf(" %c", &op);
            if(op != 'Y' && op != 'y')
            {
                printf("Modification cancelled...\n");
                break;
            }

            // Show current table
            printf("\nCurrent Records:\n");
            printf("--------------------------------------\n");
            printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
            printf("--------------------------------------\n");
            ST *temp3 = head2;
            while(temp3)
            {
                printf("|%-5d |%-20s |%-7.2f|\n", temp3->roll, temp3->name, temp3->marks);
                printf("--------------------------------------\n");
                temp3 = temp3->next;
            }

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

                    printf("Record updated temporarily.....\n");

                    printf("\nUpdated Record:\n");
                    printf("--------------------------------------\n");
                    printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                    printf("--------------------------------------\n");
                    printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
                    printf("--------------------------------------\n");
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
            printf("Do you want to perform modification based on name [Y/y]: ");
            scanf(" %c", &op);
            if(op != 'Y' && op != 'y')
            {
                printf("Modification cancelled...\n");
                break;
            }

            // Show current table
            printf("\nCurrent Records:\n");
            printf("--------------------------------------\n");
            printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
            printf("--------------------------------------\n");
            ST *temp3 = head2;
            while(temp3)
            {
                printf("|%-5d |%-20s |%-7.2f|\n", temp3->roll, temp3->name, temp3->marks);
                printf("--------------------------------------\n");
                temp3 = temp3->next;
            }

            char s[20];
            printf(" Enter the name: ");
            scanf("%s", s);

            int found = 0, count = 0;
            ST *temp2 = head2;
            while(temp2)
            {
                if(strcmp(temp2->name, s) == 0)
                {
                    found = 1;
                    count++;
                }
                temp2 = temp2->next;
            }

            if(!found)
            {
                printf("Name not found!\n");
                break;
            }

            int rollno;
            if(count == 1)
            {
                temp = head2;
                while(temp)
                {
                    if(strcmp(temp->name, s) == 0)
                    {
                        printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                               temp->roll, temp->name, temp->marks);

                        printf(" Enter new name: ");
                        scanf("%s", temp->name);

                        printf(" Enter new marks: ");
                        scanf("%f", &temp->marks);

                        printf("Record updated temporarily.....\n");

                        printf("\nUpdated Record:\n");
                        printf("--------------------------------------\n");
                        printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                        printf("--------------------------------------\n");
                        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
                        printf("--------------------------------------\n");
                        break;
                    }
                    temp = temp->next;
                }
            }
            else
            {
                printf("\nMatching records with name '%s':\n", s);
                printf("--------------------------------------\n");
                printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                printf("--------------------------------------\n");
                temp2 = head2;
                while(temp2)
                {
                    if(strcmp(temp2->name, s) == 0)
                    {
                        printf("|%-5d |%-20s |%-7.2f|\n", temp2->roll, temp2->name, temp2->marks);
                        printf("--------------------------------------\n");
                    }
                    temp2 = temp2->next;
                }

                printf("Enter roll number to modify from above list: ");
                scanf("%d", &rollno);

                temp = head2;
                while(temp)
                {
                    if(temp->roll == rollno && strcmp(temp->name, s) == 0)
                    {
                        printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                               temp->roll, temp->name, temp->marks);

                        printf(" Enter new name: ");
                        scanf("%s", temp->name);

                        printf(" Enter new marks: ");
                        scanf("%f", &temp->marks);

                        printf("Record updated temporarily.....\n");

                        printf("\nUpdated Record:\n");
                        printf("--------------------------------------\n");
                        printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                        printf("--------------------------------------\n");
                        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
                        printf("--------------------------------------\n");
                        break;
                    }
                    temp = temp->next;
                }
            }
            break;
        }

        case 'P': case 'p':
        {
            printf("Do you want to perform modification based on percentage [Y/y]: ");
            scanf(" %c", &op);
            if(op != 'Y' && op != 'y')
            {
                printf("Modification cancelled...\n");
                break;
            }

            // Show current table
            printf("\nCurrent Records:\n");
            printf("--------------------------------------\n");
            printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
            printf("--------------------------------------\n");
            ST *temp3 = head2;
            while(temp3)
            {
                printf("|%-5d |%-20s |%-7.2f|\n", temp3->roll, temp3->name, temp3->marks);
                printf("--------------------------------------\n");
                temp3 = temp3->next;
            }

            float per;
            printf(" Enter the percentage to search: ");
            scanf("%f", &per);

            int found = 0, count = 0;
            ST *temp2 = head2;
            while(temp2)
            {
                if(temp2->marks == per)
                {
                    found = 1;
                    count++;
                }
                temp2 = temp2->next;
            }

            if(!found)
            {
                printf("Percentage not found!\n");
                break;
            }

            int rollno;
            if(count == 1)
            {
                temp = head2;
                while(temp)
                {
                    if(temp->marks == per)
                    {
                        printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                               temp->roll, temp->name, temp->marks);

                        printf(" Enter new name: ");
                        scanf("%s", temp->name);

                        printf(" Enter new marks: ");
                        scanf("%f", &temp->marks);

                        printf("Record updated temporarily.....\n");

                        printf("\nUpdated Record:\n");
                        printf("--------------------------------------\n");
                        printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                        printf("--------------------------------------\n");
                        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
                        printf("--------------------------------------\n");
                        break;
                    }
                    temp = temp->next;
                }
            }
            else
            {
                printf("\nMatching records with percentage %.2f:\n", per);
                printf("--------------------------------------\n");
                printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                printf("--------------------------------------\n");
                temp2 = head2;
                while(temp2)
                {
                    if(temp2->marks == per)
                    {
                        printf("|%-5d |%-20s |%-7.2f|\n", temp2->roll, temp2->name, temp2->marks);
                        printf("--------------------------------------\n");
                    }
                    temp2 = temp2->next;
                }

                printf("Enter roll number to modify from above list: ");
                scanf("%d", &rollno);

                temp = head2;
                while(temp)
                {
                    if(temp->roll == rollno && temp->marks == per)
                    {
                        printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                               temp->roll, temp->name, temp->marks);

                        printf(" Enter new name: ");
                        scanf("%s", temp->name);

                        printf(" Enter new marks: ");
                        scanf("%f", &temp->marks);

                        printf("Record updated temporarily.....\n");

                        printf("\nUpdated Record:\n");
                        printf("--------------------------------------\n");
                        printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                        printf("--------------------------------------\n");
                        printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
                        printf("--------------------------------------\n");
                        break;
                    }
                    temp = temp->next;
                }
            }
            break;
        }

        default:
            printf("Invalid option!\n");
            break;
    }

    // Free temporary list
    while(head2)
    {
        t = head2;
        head2 = head2->next;
        free(t);
    }
}

