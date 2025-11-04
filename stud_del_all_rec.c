#include"header.h"
void stud_del_all_rec(ST **p)
{
	ST *temp;

	while(*p!=0)
	{
		temp=*p;
		*p=temp->next;
	}
		printf("deleted all the students list...\n");
}

