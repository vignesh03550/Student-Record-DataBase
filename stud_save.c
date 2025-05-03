#include"header.c"

void stud_save(ST *ptr)
{
	if(ptr==0)
	{
		printf("No records to save...\n");
		return;
	}
	FILE *fp = fopen("student.dat","w");
	while(ptr!=0)
	{
		fprintf(fp,"%d %s %f \n", ptr->rollno, ptr->name,ptr->percent);
		ptr = ptr->next;
	}
	printf("Saved Successfully\n");
}
