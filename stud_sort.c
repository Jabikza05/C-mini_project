#include"header.h"


void stud_sort(ST *p)
{
    char op;


    printf("\n________________________________\n");
    printf("|                                |\n");
    printf("| N/n : Sort with Name           |\n");
    printf("| P/p : Sort with Percentage     |\n");
    printf("|                                |\n");
    printf("----------------------------------\n");

    scanf(" %c", &op);

    if(p == NULL || p->next == NULL)
    {
        printf("No records or only one record, nothing to sort.\n");
        return;
    }

    ST *temp1, *temp2;

    switch(op)
    {
        case 'N': case 'n':
            // Bubble sort by name
            for(temp1 = p; temp1 != NULL; temp1 = temp1->next)
            {
                for(temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
                {
                    if(strcmp(temp1->name, temp2->name) > 0)
                    {
                        // swap name
                        char tname[20];
			strcpy(tname, temp1->name);
			strcpy(temp1->name, temp2->name);
		       	strcpy(temp2->name, tname);

                        // swap marks
                        float tmarks = temp1->marks;
		       	temp1->marks = temp2->marks;
			temp2->marks = tmarks;

                        // swap roll
                        int troll = temp1->roll;
		       	temp1->roll = temp2->roll;
		       	temp2->roll = troll;
                    }
                }
            }
            printf("Records sorted by Name.\n");
            break;

        case 'P': case 'p':
            // Bubble sort by marks
            for(temp1 = p; temp1 != NULL; temp1 = temp1->next)
            {
                for(temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
                {
                    if(temp1->marks < temp2->marks) // descending order
                    {
                        // swap name
                        char tname[20];
			strcpy(tname, temp1->name);
			strcpy(temp1->name, temp2->name);
			strcpy(temp2->name, tname);
                        // swap marks
                        float tmarks = temp1->marks;
			temp1->marks = temp2->marks;
			temp2->marks = tmarks;

                        // swap roll
                        int troll = temp1->roll;
			temp1->roll = temp2->roll;
		       	temp2->roll = troll;
                    }
                }
            }
            printf("Records sorted by Marks.\n");
            break;

        default:
            printf("Invalid choice for sorting.\n");
            break;
    }

    stud_show(p); // display sorted list
}

