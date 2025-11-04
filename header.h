#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct st
{

  int roll;
  char name [20];
  float marks;
  struct st*next;

}ST;


void stud_add(ST **ptr); 
void stud_del(ST **p);  
void stud_show(ST *p);   
void stud_mod(ST **p);   
void stud_save(ST *p);  
void stud_exit(ST *p);  
void stud_rev(ST **ptr);  
void stud_sort(ST *p);
void stud_del_all_rec(ST **p);  

int count(struct st *ptr);


