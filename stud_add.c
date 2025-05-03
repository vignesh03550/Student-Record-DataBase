#include"header.c"
void stud_add(ST **ptr)
{
	char op;
	do{
	ST *temp = (ST *)malloc(sizeof(ST));

	printf("Enter the name and percentage of the Student: \n");
	scanf("%s %f",temp->name,&temp->percent);

	static int roll=1;

	temp->rollno=roll++;

	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		ST *last = *ptr;

		while(last->next!=0)
			last=last->next;

		temp->next = last->next;
		last->next = temp;
	}
	printf("Do you want to enter another Record(Y/N:\n");
	scanf(" %c",&op);
	} while((op=='y')||(op=='Y'));

}
