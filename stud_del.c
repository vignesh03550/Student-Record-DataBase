#include"header.c"

void roll_del(ST**);
void name_del(ST**);

void stud_del(ST **ptr)
{
char op;
printf("R/r: enter roll to del \n");
printf("N/n: enter name to del \n");
scanf(" %c", &op);

if((op>='a') && (op<='z'))
op ^= 32;

switch(op)
{
case 'R': roll_del(ptr); break;
case 'N': name_del(ptr); break;
default: printf("Invalid input\n"); return;
}
}

void roll_del(ST **ptr)
{
int roll;
printf("Enter the Roll no to be deleted:\n");
scanf("%d", &roll);
ST*temp=(*ptr);

if((*ptr)->rollno==roll)
{
if((*ptr)->next!=0)
{
(*ptr)=(*ptr)->next;
free(temp);
return;
}
else
{
free((*ptr));
*ptr=0;
return;
}

}
else
{
ST*prv;
while((temp != 0) && (temp->rollno != roll))
{
prv=temp;
temp = temp->next;
}
if(temp!=0)
{
prv->next=temp->next;
free(temp);
return;
}
}
printf("Invalid roll\n");

}

void name_del(ST **ptr)
{
char s[30];
int c=0;

ST *temp = *ptr;

printf("Enter the Name to be Deleted..\n");
scanf("%s", s);

while(temp != 0)
{       
if(strcmp((temp->name),s) != 0)
c++;
temp = temp->next;
}
temp = *ptr;
if(c==0)
{
printf("Record not found..\n");
return;
}
else if(c==1)
{
if(strcmp(((*ptr)->name),s)==0)
{
if((*ptr)->next != 0)
{
(*ptr) = (*ptr)->next;
free(temp);
return;
}
else
{
free(temp);
*ptr = 0;
return;
}
}
}
else
{
int roll;
ST*prv;
while(temp != 0)
{       
if(strcmp((temp->name),s) == 0)
printf("%d %s %f \n",temp->rollno, temp->name, temp->percent);

temp = temp->next;
}
temp = *ptr;

printf("Enter the Roll Number you want to delete...\n");
scanf("%d", &roll);


while((temp != 0) && (temp->rollno != roll))
{
prv=temp;
temp = temp->next;
}
if(temp!=0)
{
prv->next=temp->next;
free(temp);
return;
}
}
printf("Invalid Options...\n");

}
