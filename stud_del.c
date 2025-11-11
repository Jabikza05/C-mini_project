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

    ST *temp = *p, *prev = NULL;
    int roll, rno;
    char name[20];
    char confirm;

    switch (op)
    {
        case 'R': case 'r':
            printf("Do you want to delete the data based on rollno ...[Y/y]:");
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y')
            {
                printf("\nEnter roll number to delete: ");
                scanf("%d", &roll);

                prev = NULL;
                temp = *p;
                while (temp)
                {
                    if (temp->roll == roll)
                    {
                        if (prev == NULL)
                            *p = temp->next;
                        else
                            prev->next = temp->next;
                        free(temp);
                        printf("\nRecord deleted successfully....\n");
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }

                // Show updated table
                printf("\nUpdated Records:\n");
                printf("--------------------------------------\n");
                printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                printf("--------------------------------------\n");
                temp = *p;
                while (temp)
                {
                    printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
                    printf("--------------------------------------\n");
                    temp = temp->next;
                }
            }
            else
            {
                printf("\nRecord not deleted. Returning to main menu...\n");
                return;
            }
            break;

        case 'N': case 'n':
            printf("Do you want to delete the data based on name ...[Y/y]:");
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y')
            {
                printf("\nEnter name to delete: ");
                scanf("%s", name);

                int found = 0, count = 0;
                ST *temp2 = *p;

                while (temp2)
                {
                    if (strcmp(temp2->name, name) == 0)
                    {
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

                if (count == 1)
                {
                    prev = NULL;
                    temp = *p;
                    while (temp)
                    {
                        if (strcmp(temp->name, name) == 0)
                        {
                            if (prev == NULL)
                                *p = temp->next;
                            else
                                prev->next = temp->next;
                            free(temp);
                            printf("\nRecord deleted successfully....\n");
                            break;
                        }
                        prev = temp;
                        temp = temp->next;
                    }
                }
                else
                {
                    // ✅ Display all records with same name before asking roll number
                    printf("\nMultiple records found with the same name '%s':\n", name);
                    printf("--------------------------------------\n");
                    printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                    printf("--------------------------------------\n");
                    temp2 = *p;
                    while (temp2)
                    {
                        if (strcmp(temp2->name, name) == 0)
                        {
                            printf("|%-5d |%-20s |%-7.2f|\n", temp2->roll, temp2->name, temp2->marks);
                            printf("--------------------------------------\n");
                        }
                        temp2 = temp2->next;
                    }

                    printf("Enter roll number to delete from above list: ");
                    scanf("%d", &rno);

                    prev = NULL;
                    temp = *p;
                    while (temp)
                    {
                        if (temp->roll == rno && strcmp(temp->name, name) == 0)
                        {
                            if (prev == NULL)
                                *p = temp->next;
                            else
                                prev->next = temp->next;
                            free(temp);
                            printf("\nRecord deleted successfully....\n");
                            break;
                        }
                        prev = temp;
                        temp = temp->next;
                    }
                }

                // ✅ Show updated table after deletion
                printf("\nUpdated Records:\n");
                printf("--------------------------------------\n");
                printf("|%-5s |%-20s |%-7s|\n", "Roll", "Name", "Marks");
                printf("--------------------------------------\n");
                temp = *p;
                while (temp)
                {
                    printf("|%-5d |%-20s |%-7.2f|\n", temp->roll, temp->name, temp->marks);
                    printf("--------------------------------------\n");
                    temp = temp->next;
                }
            }
            else
            {
                printf("\nRecord not deleted. Returning to main menu...\n");
                return;
            }
            break;

        default:
            printf("Invalid option!\n");
            break;
    }
}
