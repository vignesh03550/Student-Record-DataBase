#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st
{
	int rollno;
	char name[30];
	float percent;
	struct st *next;
}ST;

void stud_add(ST **);
void stud_show(ST *);
void del_all(ST **);
void stud_save(ST *);
void stud_mod(ST *);
void stud_rev(ST *);
void stud_sort(ST **);
int count(ST *);
void stud_del(ST **);
int stud_exit(ST **);
