#include"header.c"

void s_free(ST **);

int stud_exit(ST **ptr)
{
	char op;
	printf("Enter \n S/s : Save & Exit \n N/n: exit without saving \n");
	scanf(" %c", &op);

	if((op=='S') || (op=='s'))
	{
		stud_save(*ptr);
		s_free(ptr);
		return 0;
	}
	else if((op=='N') || (op=='n'))
	{
		printf("Do you want to exit without saving (Y/N)\n");
		scanf(" %c", &op);
		
		if((op=='Y') || (op=='y'))
		{	
			s_free(ptr);
			return 0;
		}
		else if((op=='N') || (op=='n'))
			return 1;		
	}

}

void s_free(ST **ptr)
{
	ST *temp = *ptr;
	while((*ptr) != 0)
	{
		free(temp);
		*ptr = (*ptr)->next;
		temp = *ptr;
	}
	*ptr = 0;
}
