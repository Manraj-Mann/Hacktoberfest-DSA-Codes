#include <iostream>
using namespace std;
//creating a structure
struct Node{
	int data;
	Node *next;
};
// creating  front and rear POINTERS AND FUNCTION/METHODS TO Perform the operations on Queue
class Queue{
	public:
		Node*front;
		Node*rear;
		Queue();
		
		//methods
		void enqueue(int n);
		void dequeue();
		void print();
		void sort();
};
//constructor
Queue::Queue(){
	front=NULL;
	rear=NULL;
}

void Queue::dequeue(){
	//checking if the list is empty
	if(front==NULL){
		cout<<"The queue is Empty. Deletion is not possible!!!"<<endl;
	}
	else{
		Node*ptr=front;
		front=front->next;
		delete ptr;
		cout<<"The node at the front has been deleted SUCCESSFULLY!"<<endl;
	}
}

void Queue::enqueue(int n){
	Node* new_node= new Node;
	new_node->data=n;
	new_node->next=NULL;
	//checking if the list is empty
	if(front==NULL){
		front=rear=new_node;
	}
	else{
		rear->next=new_node;
		rear=new_node;
	}
    cout<<"\nInsertion is Successful!!!\n";
}

void Queue::sort(){
	//first we will make two pointers so we can swap whenever we find a smaller value
	Node*temp1=front;
	Node*temp2;
	//checking if the queue is empty
	if(front==NULL){
		cout<<"The queue is Empty!"<<endl;
	}
	else{
		while(temp1->next!=NULL){
			temp2=temp1->next;
			while(temp2!=NULL){
				//checking the condition if temp1 has a greater value
				if(temp1->data>temp2->data){
					//if true then we swap the values and create a new pointer to help in swapping
					int ptr;
					ptr=temp1->data;
					temp1->data=temp2->data;
					temp2->data=ptr;
				}
				//now moving temp2 to the next node to check if it contains a smaller value
				temp2=temp2->next;
			}
			//now we are sure that we have the smallest vale in the start so moving temp1 to the next node
			temp1=temp1->next;
		}
	}
}

void Queue::print(){
	Node*temp1=front;
	
	while(temp1!=NULL){
		cout<<" "<<temp1->data<<endl;
		temp1=temp1->next;
	}
}

int main(){
	Queue Q1;
	Q1.enqueue(12);
	Q1.print();
	Q1.enqueue(6);
	Q1.print();
	Q1.enqueue(4);
	Q1.print();
	Q1.sort();
	cout<<"\n-----------------Sorted according to priority---------------\n";
	Q1.print();
	Q1.dequeue();
	Q1.print();
	return 0;
}
