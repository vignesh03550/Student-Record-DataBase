#include "header.c"

/*int count(ST *ptr)
{
	int c=0;
	while(ptr!=0)
	{
		c++;
		ptr = ptr->next;
	}
	return c;
}*/
void stud_rev(ST *ptr)
{
	ST temp;
	int i,j,c=count(ptr);
	int size=(sizeof(ST) - sizeof(ST*));

	ST **p = (ST**)malloc(c*sizeof(ST*));

	for(i=0;i<c;i++)
	{
		p[i] = ptr;
		ptr = ptr->next;
	}	

	for(i=0,j=c-1;i<j;i++,j--)
	{
		memcpy(&temp.rollno,&p[i]->rollno,size);
		memcpy(&p[i]->rollno,&p[j]->rollno,size);
		memcpy(&p[j]->rollno,&temp.rollno,size);

	}
}
