#include"header.h"


void stud_del(ST **p)
{
    char op;

    printf("\n________________________________\n");
    printf("|                                |\n");
    printf("| R/r : enter roll to del        |\n");
    printf("| N/n : enter name to del        |\n");
    printf("|                                |\n");
    printf("----------------------------------\n");

    scanf(" %c",&op);

    switch(op)
    {
        case 'R': case 'r':
        {
            int n;
            printf(" Enter the roll no: ");
            scanf("%d", &n);

            ST *last = NULL, *temp = *p;

            while(temp != NULL)
            {
                if(temp->roll == n)
                {
                    if(temp == *p)
                        *p = temp->next;
                    else
                        last->next = temp->next;

                    free(temp);
                    printf("Deleted the particular roll no record...\n");
                    return;
                }
                last = temp;
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
            else if(count == 1)
            {
                ST *last = NULL;
                temp = *p;
                while(temp != NULL)
                {
                    if(strcmp(temp->name, s) == 0)
                    {
                        if(temp == *p)
                            *p = temp->next;
                        else
                            last->next = temp->next;

                        free(temp);
                        printf("Deleted the record with name %s\n", s);
                        return;
                    }
                    last = temp;
                    temp = temp->next;
                }
            }
            else
            {
                printf("\nMatching records for name \"%s\":\n", s);
                temp = *p;
                while(temp != NULL)
                {
                    if(strcmp(temp->name, s) == 0)
                        printf(" Roll: %d ", temp->roll);
                    temp = temp->next;
                }

                int n;
                printf("\n Enter the roll no to delete: ");
                scanf("%d", &n);

                ST *last = NULL;
                temp = *p;
                while(temp != NULL)
                {
                    if(temp->roll == n && strcmp(temp->name, s) == 0)
                    {
                        if(temp == *p)
                            *p = temp->next;
                        else
                            last->next = temp->next;

                        free(temp);
                        printf("Deleted record with roll %d and name %s\n", n, s);
                        return;
                    }
                    last = temp;
                    temp = temp->next;
                }

                printf("Roll no not found for the given name!\n");
            }

            break;
        }

        default:
            printf("\nInvalid choice...\n");
            break;
    }
}

