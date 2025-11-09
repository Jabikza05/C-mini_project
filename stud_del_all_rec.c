#include"header.h"
void stud_del_all_rec(ST **p)
{
	ST *temp;
   char op;
	
	printf("Do you want to delete all the Records....[Y/y]:");
	scanf(" %c",&op);
	if(op=='Y'||op=='y')
	{
	while(*p!=0)
	{
		temp=*p;
		*p=temp->next;
		free(temp);
	 }
		printf("deleted all the students list...\n");
    }
    else
    {
	    printf("Records are not deleted....");
    }
}
