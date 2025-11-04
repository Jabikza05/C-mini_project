#include"header.h"



void stud_mod(ST **p)
{
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

    switch(op)
    {
        case 'R': case 'r':
        {
            int n;
            printf(" Enter the roll no to modify: ");
            scanf("%d", &n);

            ST *temp = *p;

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

                    printf("Record updated successfully!\n");
                    return;
                }
                temp = temp->next;
            }
            printf("Roll no not found!\n");
            break;
        }

        case 'N': case 'n':
        {
            char s[20];
            printf(" Enter the name: ");
            scanf("%s", s);

            ST *temp = *p;
            int count = 0;

            // Count occurrences
            while(temp != NULL)
            {
                if(strcmp(temp->name, s) == 0)
                    count++;
                temp = temp->next;
            }

            if(count == 0)
            {
                printf("Name not found!\n");
                break;
            }

            printf("\nMatching records for name \"%s\":\n", s);
            temp = *p;
            while(temp != NULL)
            {
                if(strcmp(temp->name, s) == 0)
                    printf(" Roll: %d ", temp->roll);
                temp = temp->next;
            }

            int n;
            printf("\n Enter the roll no of record to modify: ");
            scanf("%d", &n);

            temp = *p;
            while(temp != NULL)
            {
                if(temp->roll == n && strcmp(temp->name, s) == 0)
                {
                    printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                            temp->roll, temp->name, temp->marks);

                    printf(" Enter new name: ");
                    scanf("%s", temp->name);

                    printf(" Enter new marks: ");
                    scanf("%f", &temp->marks);

                    printf("Record updated successfully!\n");
                    return;
                }
                temp = temp->next;
            }

            printf("Roll no not found for given name!\n");
            break;
        }

        case 'P': case 'p':
        {
            float perc;
            printf(" Enter the percentage (marks) to search: ");
            scanf("%f", &perc);

            ST *temp = *p;
            int count = 0;

            // Count occurrences
            while(temp != NULL)
            {
                if(temp->marks == perc)
                    count++;
                temp = temp->next;
            }

            if(count == 0)
            {
                printf("Percentage not found!\n");
                break;
            }

            printf("\nMatching records for percentage %.2f:\n", perc);
            temp = *p;
            while(temp != NULL)
            {
                if(temp->marks == perc)
                    printf(" Roll: %d Name: %s ", temp->roll, temp->name);
                temp = temp->next;
            }

            int n;
            printf("\n Enter the roll no of record to modify: ");
            scanf("%d", &n);

            temp = *p;
            while(temp != NULL)
            {
                if(temp->roll == n && temp->marks == perc)
                {
                    printf("Record found: Roll = %d, Name = %s, Marks = %.2f\n",
                            temp->roll, temp->name, temp->marks);

                    printf(" Enter new name: ");
                    scanf("%s", temp->name);

                    printf(" Enter new marks: ");
                    scanf("%f", &temp->marks);

                    printf("Record updated successfully!\n");
                    return;
                }
                temp = temp->next;
            }

            printf("Roll no not found for given percentage!\n");
            break;
        }

        default:
            printf("Invalid option!\n");
    }
}
