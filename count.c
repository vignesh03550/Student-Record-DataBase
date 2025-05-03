#include"header.c"

int count(ST *ptr)
{
	int c=0;
	while(ptr != 0)
	{
		c++;
		ptr = ptr->next;
	}
	return c;
}
