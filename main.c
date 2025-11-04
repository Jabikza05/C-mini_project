#include"header.h"

int main()
{

   ST*hptr=0;
   char op;

do
{       
    printf("\n_________________________________________\n");
      printf("|                                       |\n");
      printf("|   *****STUDENT RECORD MENU*****       |\n");
      printf("|   ----------------------------------  |\n");
      printf("|                                       |\n");
      printf("|  a/A :add new record                  |\n");
      printf("|  d/D :delete a record                 |\n");
      printf("|  s/S :show the list                   |\n");
      printf("|  m/M :modify a record                 |\n");
      printf("|  v/V :save                            |\n");
      printf("|  e/E :exit                            |\n");
      printf("|  t/T :sort the list                   |\n");
      printf("|  l/L :delete all the record           |\n");
      printf("|  r/R :reverse the list     	        |\n");
      printf("|                                       |\n");
      printf("|                                       |\n");
      printf("|  Enter your choice:                   |\n");
      printf("-----------------------------------------\n");
  
   scanf(" %c",&op);
 
 

  switch(op)
  {
    case 'a':
    case 'A':   
        stud_add(&hptr);  
        break;

    case 'd':
    case 'D':
        stud_del(&hptr);
        break;

    case 's':
    case 'S':
        stud_show(hptr);
        break;

    case 'm':
    case 'M':
        stud_mod(&hptr);
        break;

    case 'v':
    case 'V':
        stud_save(hptr);
        break;

    case 'e':
    case 'E':
        stud_exit(hptr);
        break;

    case 't':
    case 'T':
        stud_sort(hptr);   
       break;

    case 'l':
    case 'L':
        stud_del_all_rec(&hptr);
        break;

    case 'r':
    case 'R':
        stud_rev(&hptr);
        break;

    default:
        printf("invalid operation\n");
        break;
   }

}
   while(1);
  }



