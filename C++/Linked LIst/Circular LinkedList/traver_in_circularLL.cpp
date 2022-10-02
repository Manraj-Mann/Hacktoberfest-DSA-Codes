#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *next;
} cll;
void traverse(cll *head)
{
    cout<<"The list contains : ";

    cll *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;

    } while (current != head);
    cout<<endl;
}
// Time Complexity: O(n), for scanning the complete list of size n.
// Space Complexity: O(1), for temporary variable.
int main()
{
    cll * head;
    cll * node1 , * node2 , * node3 , *node4 , *node5 ;

    node1  = new cll;
    node2  = new cll;
    node3  = new cll;
    node4  = new cll;
    node5  = new cll;

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;

    traverse(head);
    return 0;

    
}