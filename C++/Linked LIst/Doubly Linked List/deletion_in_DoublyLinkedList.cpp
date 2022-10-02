#include <iostream>
using namespace std;
typedef struct DoublyLinkedList
{
    int data;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;

} dll;
/*

        • Deleting the first node
        • Deleting the last node
        • Deleting an intermediate node

*/

int Traverse(dll *head, int type)
{

    cout << "The data is : ";

    int count = 0;
    if (type == 1)
    {

        dll *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
            count++;
        }
    }
    else
    {

        dll *current = head;
        while (current->next != NULL)
        {

            current = current->next;
            count++;
        }

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->prev;
        }
    }
    cout << endl;

    return count;

    //   Time Complexity: O(n), for scanning the list of size n.
    //   Space Complexity: O(1), for creating a temporary variable.
}
void delete_at_first(dll ** head){

    dll * temp = *head;

    *head = (*head)->next;
    (*head)->prev = NULL;

    delete temp;

}

void delete_at_last(dll ** head ){
    
    dll * temp = *head;
    dll * newlast;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    newlast = temp->prev;

    newlast->next = NULL;

    delete temp;

    
}
void delete_at_given( dll ** head , int pos){

    dll * temp = *head;
    dll * p;
    dll * q;
    int k = 1;

    while (k != pos)
    {
        temp = temp->next;
        k++;
    }

    // Improve space complexity 

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;



    // p = temp->prev;

    // p->next = temp->next;
    
    // q = temp->next;

    // q->prev = temp->prev;
 

    delete temp;


    
}
int main()
{
    dll *head;

    dll *node1 = new dll;
    dll *node2 = new dll;
    dll *node3 = new dll;
    dll *node4 = new dll;
    dll *node5 = new dll;

    head = node1;
    node1->data = 1;
    node1->next = node2;
    node1->prev = NULL;

    node2->data = 2;
    node2->next = node3;
    node2->prev = node1;

    node3->data = 3;
    node3->next = node4;
    node3->prev = node2;

    node4->data = 4;
    node4->next = node5;
    node4->prev = node3;

    node5->data = 5;
    node5->next = NULL;
    node5->prev = node4;


    Traverse(head , 1);
    Traverse(head , 2);

    delete_at_first(&head);

    Traverse(head , 1);
    Traverse(head , 2);

    delete_at_last(&head);

    Traverse(head , 1);
    Traverse(head , 2);

    delete_at_given(&head , 2);

    Traverse(head , 1);
    Traverse(head , 2);
    return 0;
}