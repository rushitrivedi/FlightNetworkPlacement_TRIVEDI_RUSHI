#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
int mstack[10];
int mpattern[10];
static int top = 0;
static int npush = 0;

void push(int digit)
{
if(mstack[top-1] == 9)
{
cout<<"\n\n\t STACK UNDERFLOW!";
return;
}
if(top == 0 || npush == digit) 
{
mstack[top++] = digit;
npush = digit+1;
cout<<"\n\n\t DATA IS PUSHED";
return;
}
cout<<"\n\n\t IT IS NOT VALID PUSH OPERATION";
}

int pop()
{
if(top == 0)
{
cout<<"\n\n\tStack Empty!";
return -1;
}
return  mstack[--top];
}

void show_stack()
{
int i;
cout<<"\n\n\t\tCurrent  value of Stack : \n\t";
for(i = top; i > 0; i--)
cout<<"  "<<mstack[i-1];
if(top == 0)
cout<<"STACK OVERFLOW!";
}

void menu()
{
cout<<"\n\n\t\t Select an Operation : ";
cout<<"\n\n\t   1. Push.";
cout<<"\n\t   2. Pop.";
cout<<"\n\t   3. Show.";
cout<<"\n\t   4. Pattern matching.";
cout<<"\n\t   5. Exit.";
cout<<"\n\n\tEnter Here : ";
}

int validate()
{
int i;
for(i = 0; i<=9; i++)
{
//if(pattern[i]>9 || pattern[i]<0)
if(!isdigit(pattern[i]))
return 0;
}

int status[10];
for(i = 0; i<10; i++)
status[i] = 1;

for(i = 0; i<9; i++)
{
if(status[pattern[i]])
status[pattern[i]] = 0;
else
return 0;

if(pattern[i]>pattern[i+1])
{
if((pattern[i] - pattern[i+1]) != 1)
{
int j;
for(j = pattern[i]-1; j>pattern[i+1]; j--)
{
if(status[j])
return 0;
}
}
}
}

return 1;
}

int main()
{
int choice, digit,f;
clrscr();
do
{
menu();
cin>>choice;

switch(choice)
{
case 1: cout<<"\n\n\tEnter Digit : ";
	cin>>digit;
	push(digit);
	break;

case 2: int num = pop();
	if(num != -1)
	cout<<"\n\n\tPopped Digit : "<<num;
	break;

case 3: show_stack();
	break;
case 4: cout<<"Enter a pattern of 10 distinct digits (seperated by space) : ";
	int i;
	for(i = 0; i<=9; i++)
	{	cin>>pattern[i];
		if(!isdigit(pattern[i]))
		{
			cout<<"Enter correct digit";
			break;
			f=1;
			}
		}
	  if(f==1)
	  {	break;	}
	if(validate())
	cout<<"\n\n\tValid Pattern!";
	else
	cout<<"\n\n\tInvalid Pattern!";
	break;
}
}
while(choice != 5);
getch();
return 0;
}