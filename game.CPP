#include<iostream.h>
#include<conio.h>
#include<stdlib.h> //for malloc function

struct Node  //structure for generating circular queue
{
int value;          //node value and
struct Node *link;  //link that points to next node
};

typedef struct Node cqueue; //typedefine

cqueue* insert(int data, cqueue *head)
{
cqueue *temp = head->link, *newnode = NULL;
while(temp->link != head->link)
{
	temp = temp->link;
}

newnode = (cqueue*)malloc(sizeof(cqueue)); //allocting node memory
newnode->value = data;
if(head == NULL)
{
newnode->link = newnode;
return newnode;
}
else if(temp == head)
{
newnode->link = newnode;
head->link = newnode;
return head;
}
newnode->link = temp->link;
temp->link = newnode;

return head;
}

cqueue* delete_data(int data, cqueue *head)
{
cqueue *temp = head->link->link, *prev = head->link;
while(temp->value != data)
{
prev = temp;
temp = temp->link;
}
if(temp == head->link)
{
head->link = temp->link;
}

prev->link = temp->link;

return head;
}

void traverse(cqueue *head)
{
cqueue *temp=head->link;
while(temp->link!=head->link)
{
cout<<"\n  Data : "<<temp->value;
temp = temp->link;
}
cout<<"\n  Data : "<<temp->value;
}

int get_winner(int n, cqueue *head)
{
cqueue *temp = head->link;
int j=1;
while(head->link->link != head->link)
{
for(int i=2;i<=n;i++)
{
temp=temp->link;
}
head=delete_data(temp->value,head);
cout<<"\n\n\n\tRound : "<<j++;
cout<<"\n  Deleted Position : "<<temp->value;
temp=temp->link;
cout<<"\n  Next Start at Position : "<<temp->value<<endl;
traverse(head);
getch();//this is becoz u can see proper output
}
return head->link->value;//last node value which is winner
}


int main()
{
int M=0,N=0;//Initialization of Variables.
clrscr();   //clearscreen

cqueue *head=insert(0,NULL);//first node starting with 0

cout<<"\n\tEnter M :: ";
cin>>M;
cout<<"\n\tEnter N :: ";
cin>>N;

for(int count=1;count<=M;count++)
{
head=insert(count,head);
}
cout<<"\n\n\tOriginal Sequence : \n";
traverse(head);
cout<<"\n\tWinner For M :: "<<M;
cout<<" and N :: "<<N;
cout<<" is at Position :: "<<get_winner(N,head);
getch();
return 0;
}