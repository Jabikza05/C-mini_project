#include"header.h"

void stud_save(ST *p)
{
    FILE *fp;
    char ch;

    printf("\n_____________________________\n");
    printf("|                             |\n");
    printf("| S/s : save and exit         |\n");
    printf("| E/e : exit without saving   |\n");
    printf("|                             |\n");
    printf("-------------------------------\n");

    scanf(" %c", &ch);

    switch(ch)
    {
        case 'S':
        case 's':
              printf("Do you want to save and exit ...[Y/y]:");
            scanf(" %c",&ch);
            if(ch=='Y'||ch=='y')
            {
            fp = fopen("student.dat", "w");  // open once in write mode
            if(fp == 0)
            {
                printf("File open failed...\n");
                return;
            }

            while(p != 0)  // write all nodes
            {
                fprintf(fp, "%d %s %.2f\n", p->roll, p->name, p->marks);
                p = p->next;
            }

            
            fclose(fp);
            }
            else
            {
                printf("All records saved successfully into student.dat\n");
            exit(0);
            }
            break;

        case 'E':
        case 'e':
             printf("Do you want to Exit without saving....[Y/y]:");
            scanf(" %c",&ch);
            if(ch=='Y'||ch=='y')
            {
            printf("Exit without saving...\n");
            exit(0);
            }
            break;

        default:
            printf("Invalid choice...\n");
            break;
    }
}



