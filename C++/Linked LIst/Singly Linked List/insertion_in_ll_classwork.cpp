#include <iostream>
using namespace std;
struct node{

    int data;
    node * next;

};

void create(node * ptr){
    int num;
    cout<<"Total nodes = ";cin>>num;
    int n = 0;
    while (n < num){
    
        cout<<"Enter data "<<n+1<<" node : ";cin>>ptr->data;
        ptr->next = new node;
        ptr = ptr->next;
        n++;
    }
    ptr->next = NULL;
     
}
void traverse(node * ptr){

    while (ptr->next != NULL)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
    
}
node * start;

int main(){

    start = new node;

    create(start);
    traverse(start);

    
return 0;
}