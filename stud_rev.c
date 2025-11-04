#include"header.h"
void stud_rev(ST **ptr)
{
	int i,c=count(*ptr);

	ST *temp=*ptr;

	ST  **p=(ST**)malloc(c*sizeof(ST*));

	for(i=0;i<c;i++)
	{
		p[i]=temp;
		temp=temp->next;
	}
	
	p[0]->next=0;

	for(i=1;i<c;i++)
		p[i]->next=p[i-1];

	*ptr=p[c-1];

	printf("The student record's are reverse linked...\n");
 stud_show(*ptr);  // show reversed list

    free(p); 
}


int count(struct st *ptr)
{
int c=0;
	while(ptr!=0)
	{
		++c;
		ptr=ptr->next;
	}
	return c;
}


