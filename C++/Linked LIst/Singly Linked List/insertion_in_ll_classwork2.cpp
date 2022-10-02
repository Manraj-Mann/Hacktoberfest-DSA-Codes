#include <iostream>
using namespace std;
struct node{

    int data;
    node * next;

};
node * start;

node * create(){
    int num;
    cout<<"Total nodes = ";cin>>num;
    start = new node;
    node * ptr = start;
    int n = 0;
    while (n < num){
    
        cout<<"Enter data "<<n+1<<" node : ";cin>>ptr->data;
        ptr->next = new node;
        ptr = ptr->next;
        n++;
    }
    ptr->next = NULL;

    return start;
     
}
void traverse(node * ptr){

    while (ptr->next != NULL)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
    
}

int main(){

    

    start = create();
    traverse(start);

    
return 0;
}