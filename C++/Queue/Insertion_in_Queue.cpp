#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

int insert_in_queue(int [], int);
void display(int [], int, int);

const int SIZE = 50;

int queue[SIZE];
int front=-1;
int rear=-1;

void main()
{
   clrscr();
   int item, check;
   char ch='y';

   while(ch=='y' || ch=='Y')
   {
      cout<<"Enter item for insertion: ";
      cin>>item;
      check = insert_in_queue(queue, item);
      if(check == -1)
      {
         cout<<"\nOverflow..!!..Aborting..!!..Press a key to exit..\n";
         getch();
         exit(1);
      }
      cout<<"Item inserted successfully..!!\n";
      cout<<"\nNow the Queue (Front...to...Rear) is:\n";
      display(queue, front, rear);
      cout<<"\nWant to insert more ? (y/n).. ";
      cin>>ch;
   }
   getch();
}

int insert_in_queue(int queue[], int elem)
{
   if(rear == SIZE-1)
   {
      return -1;
   }
   else if(rear == -1)
   {
      front = rear = 0;
      queue[rear] = elem;
   }
   else
   {
      rear++;
      queue[rear] = elem;
   }
   return 0;
}

void display(int queue[], int front, int rear)
{
   if(front == -1)
   {
      return;
   }
   for(int i=front; i<rear; i++)
   {
      cout<<queue[i]<<" <- ";
   }
   cout<<queue[rear]<<"\n";
}
