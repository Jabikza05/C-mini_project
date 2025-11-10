#include "header.h"

// SAVE FUNCTION — saves records in a proper box-style table format
void stud_save(ST *p)
{
      FILE *fp;
      char ch;
      
    printf("\nDo you want to save the records into file 'student.dat'? [Y/y]: ");
    scanf(" %c", &ch);

   if (ch == 'Y' || ch == 'y')  
   {

    fp = fopen("student.dat", "w");
    if (fp == NULL)
    {
        printf(" File open failed...\n");
        return;
    }

    // Table Header
    fprintf(fp, "+----------+----------------------+----------+\n");
    fprintf(fp, "| %-8s | %-20s | %-8s |\n", "Roll No", "Name", "Marks");
    fprintf(fp, "+----------+----------------------+----------+\n");

    // Each Record Row
    while (p != NULL)
    {
        fprintf(fp, "| %-8d | %-20s | %-8.2f |\n", p->roll, p->name, p->marks);
        fprintf(fp, "+----------+----------------------+----------+\n");
        p = p->next;
    }

    fclose(fp);
    printf("\n Records saved successfully into 'student.dat'.....\n");
}
}
