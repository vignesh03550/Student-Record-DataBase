#include"header.c"

void sort_name(ST **);
void sort_percent(ST **);

void stud_sort(ST **ptr)
{
	char op;
	printf("N/n: sort with name\n");
	printf("P/p: sort with percentage\n");

        scanf(" %c",&op);
	if((op>='a')&&(op<='z'))
		op=op^32;
	
	switch(op)
	{
		case 'N':sort_name(ptr);break;
		case 'P':sort_percent(ptr);break;
		default: printf("Invalid input \n"); return;
	}
}
void sort_name(ST **ptr)
{
	int i,j,size=(sizeof(ST) - sizeof(ST*));
	int c=count(*ptr);
	
	ST temp;

	ST **p = (ST **)malloc(c*sizeof(ST *));

	for(i=0;i<c;i++)
	{
		p[i] = *ptr;
		*ptr = (*ptr)->next;
	}

	for(i=0;i<c-1;i++)
	{
		for(j=0;j<c-i-1;j++)
		{
			if(strcmp((p[j]->name),(p[j+1]->name))>0)
			{
				memcpy(&temp.rollno,&p[j]->rollno,size);
				memcpy(&p[j]->rollno,&p[j+1]->rollno,size);
				memcpy(&p[j+1]->rollno,&temp.rollno,size);
			}

		}
	}
	*ptr = p[0];

}

void sort_percent(ST **ptr)
{
	int i,j,size=(sizeof(ST) - sizeof(ST*));
	int c=count(*ptr);
	
	ST temp;

	ST **p = (ST **)malloc(c*sizeof(ST *));

	for(i=0;i<c;i++)
	{
		p[i] = *ptr;
		*ptr = (*ptr)->next;
	}

	for(i=0;i<c-1;i++)
	{
		for(j=0;j<c-i-1;j++)
		{
			if((p[j]->percent) > (p[j+1]->percent))
			{
				memcpy(&temp.rollno,&p[j]->rollno,size);
				memcpy(&p[j]->rollno,&p[j+1]->rollno,size);
				memcpy(&p[j+1]->rollno,&temp.rollno,size);
			}

		}
	}
	*ptr = p[0];
}



// A sarathy 55.2 A sunil 152.333 A Ani 122.54 A Krishna 654.5165 A Sandal 2
