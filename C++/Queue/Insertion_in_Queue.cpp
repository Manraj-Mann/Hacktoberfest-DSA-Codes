#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

int insert_in_queue(int [], int);
void display(int [], int, int);

const int SIZE = 50;

int queue[SIZE];

//We have two ends i.e. “front” and “rear” of the queue. When the queue is empty, then both the pointers are set to -1.
//The “rear” end pointer is the place from where the elements are inserted in the queue. The operation of adding /inserting elements in the queue is called “enqueue”.
//The “front” end pointer is the place from where the elements are removed from the queue. The operation to remove/delete elements from the queue is called “dequeue”.

int front=-1;
int rear=-1;

void main()
{
   int item, check;
   char ch='y';
// Asking the user to input Y or y incase he wants to add one more element in the queue i.e. enque operation
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

//When the rear pointer value is size-1, then we say that the queue is full. When the front is null, then the queue is empty.

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

// Display the cuurent queue formed as a result of enqueue operation

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
