#include"header.h"

void stud_add(struct st **ptr)
{
    FILE *fp;
    struct st *temp, *p, *last;

    // Load existing records from file
    fp = fopen("student.dat", "r");
    if (fp != NULL)
    {
        while (1)
        {
            temp = (struct st *)malloc(sizeof(struct st));
            if (fscanf(fp, "%d %s %f", &temp->roll, temp->name, &temp->marks) != 3)
            {
                free(temp);
                break;
            }
            temp->next = 0;

            if (*ptr == 0)
                *ptr = last = temp;
            else
            {
                last->next = temp;
                last = temp;
            }
        }
        fclose(fp);
    }

    // Add new student
    temp = (struct st *)malloc(sizeof(struct st));

    printf("Enter the data..name and marks\n");
    scanf("%s%f", temp->name, &temp->marks);
    temp->next = 0;

    // Find smallest available roll number
    int r = 1;
    p = *ptr;
    while (p != 0)
    {
        if (p->roll == r)
        {
            r++;
            p = *ptr; // restart from head to check again
        }
        else
            p = p->next;
    }
    temp->roll = r;

    // Insert at end of list
    if (*ptr == 0)
        *ptr = temp;
    else
    {
        p = *ptr;
        while (p->next != 0)
            p = p->next;
        p->next = temp;
    }

//    printf("Record added successfully! Roll number: %d\n", temp->roll);
}
