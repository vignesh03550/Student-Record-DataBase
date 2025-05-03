#include"header.c"

void mod_roll(ST *);
void mod_name2(ST *,char *);
void mod_name(ST *);
void mod_percent(ST *);
void mod_percent2(ST *, float);

void stud_mod(ST *ptr)
{
	char op;
	printf("Enter which record to search for modification\n");
	printf("R/r: to search a roll number\n");
	printf("N/n: to search a name\n");
	printf("P/p: percentage based\n");

	scanf(" %c", &op);
	if((op>='a')&&(op<='z'))
		op = op^32;

	switch(op)
	{
		case 'R': mod_roll(ptr); break;
		case 'N': mod_name(ptr); break;
		case 'P': mod_percent(ptr); break;
		default: printf("Invalid Input\n"); return;
	}
}

void mod_roll(ST *ptr)
{
	int roll,n;
	printf("Enter the Roll Number to search:\n");
	scanf("%d", &roll);

	while((ptr->rollno !=  roll) && (ptr != 0))
		ptr = ptr->next;

	if(ptr->rollno == roll)
	{
		printf("Roll No is found...\n");
		printf("Enter the new roll number to be updated: ");
		scanf("%d", &n);

		ptr->rollno = n;
		return;
	}
	else
		printf("Roll No not found....\n");
}

void mod_name(ST *ptr)
{
	ST *temp= ptr;
	int roll,c=0;
	char name[30],n[30];
	printf("Enter the Name to search:\n");
	scanf("%s", name);

	while(ptr != 0)
	{	
		if(strcmp((ptr->name),name)==0)
			++c;
			
		ptr = ptr->next;
	}
	ptr = temp;

	if(c==1)
	{
		mod_name2(ptr,name);
		return;
	}

	while(ptr != 0)
	{	
		if(strcmp((ptr->name),name)==0)
			printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percent);
			
		ptr = ptr->next;
	}
	ptr = temp;
	
	printf("Enter the Roll Number:\n");
	scanf("%d", &roll);
	
	while((ptr->rollno != roll) && (ptr != 0))
		ptr = ptr->next;
	
	if(ptr->rollno == roll)
	{
		printf("Enter the new name to be updated: ");
		scanf("%s", n);

		strcpy((ptr->name),n);
		return;
	}
	else
		printf("Enter the correct Roll no\n"); 

}

void mod_percent(ST *ptr)
{
	ST *temp= ptr;
	int roll,c=0;
	float percent,n;
	printf("Enter the Percent to search:\n");
	scanf("%f", &percent);

	while(ptr != 0)
	{	
		if(ptr->percent==percent)
			++c;

		ptr = ptr->next;
	}
	ptr = temp;
	
	if(c==1)
	{
		mod_percent2(ptr,percent);
		return;
	}
	
	while(ptr != 0)
	{	
		if(ptr->percent==percent)
			printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percent);

		ptr = ptr->next;
	}
	
	ptr = temp;

	printf("Enter the Roll Number:\n");
	scanf("%d", &roll);
	
	while((ptr->rollno !=  roll) && (ptr != 0))
		ptr = ptr->next;

	if(ptr->rollno == roll)
	{
		printf("Enter the new percentage to be updated: ");
		scanf("%f",&n);

		ptr->percent=n;
	}
}

void mod_name2(ST *ptr, char *s)
{
	char name[30],ch[30];
	strcpy(name,s);
	while(ptr != 0)
	{
		if((strcmp((ptr->name),name))==0)
				break;

		ptr = ptr->next;
	}

	printf("Enter the Name to be updated: \n");
	scanf("%s", ch);

	strcpy((ptr->name),ch);
	return;
}


void mod_percent2(ST *ptr,float f)
{
	float percent;
	while(ptr != 0)
	{
		if((ptr->percent)==f)
			break;

		ptr = ptr->next;
	}

	printf("Enter the Percentage to be updated: \n");
	scanf("%f", &percent);

	ptr->percent = percent;
	return;
}
