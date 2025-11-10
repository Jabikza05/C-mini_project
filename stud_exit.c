#include "header.h"

void stud_exit(ST *p)
{
    char ch;

    printf("\n_____________________________\n");
    printf("|                             |\n");
    printf("| S/s : Save and Exit         |\n");
    printf("| E/e : Exit without Saving   |\n");
    printf("|                             |\n");
    printf("-------------------------------\n");

    scanf(" %c", &ch);

    switch(ch)
    {
        case 'S':
        case 's':
            printf("Do you want to save and exit ...[Y/y]: ");
            scanf(" %c", &ch);

            if (ch == 'Y' || ch == 'y')
            {
                FILE *fp = fopen("student.dat", "w");
                if (fp == NULL)
                {
                    printf(" File open failed...\n");
                    return;
                }

                while (p != NULL)
                {
                    fprintf(fp, "%d %s %.2f\n", p->roll, p->name, p->marks);
                    p = p->next;
                }

                fclose(fp);
                printf("\n Records saved and program is exited....\n");

                // Free memory before exit
              ST *temp;
                while (p != NULL)
                {
                    temp = p;
                    p = p->next;
                    free(temp);
                }

                exit(0);
            }
            else
            {
                printf(" Save cancelled. Returning to program...\n");
                return;
            }
            break;

        case 'E':
        case 'e':
            printf("Do you want to Exit without saving....[Y/y]: ");
            scanf(" %c", &ch);

            if (ch == 'Y' || ch == 'y')
            {
                printf(" Exiting without saving.......\n");

                ST *temp;
                while (p != NULL)
                {
                    temp = p;
                    p = p->next;
                    free(temp);
                }

                exit(0);
            }
            else
            {
                printf(" Exit cancelled. Returning to program.....\n");
                return;
            }
            break;

        default:
            printf("\n Invalid choice! \n");
            return;
    }
}

