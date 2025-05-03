#include"header.c"

void del_all(ST **ptr)
{
	char op;
	printf("Confirmation Required...\n");
	printf("Do you want to delete all student records?\n");
	printf("If yes, press (Y/N): \n");
	scanf(" %c", &op);

	if((op=='Y') || (op=='y'))
	{	
		ST *temp;
		while(*ptr != 0)
		{
			temp=*ptr;
			(*ptr) =(*ptr)->next;
			free(temp);
		}
	}
	else 
		return;
}
