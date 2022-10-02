#include <iostream>
using namespace std;

typedef struct DoublyLinkedList
{
    int data;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;

} dll;

/*

        • Inserting a new node before the head.
        • Inserting a new node after the tail (at the end of the list).
        • Inserting a new node at the middle of the list.
        
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

// Impelemeting all types of insertions individually

void insert_at_begin(dll **head, int data)
{

    dll *newnode = new dll;
    newnode->data = data;
    newnode->next = *head;
    (*head)->prev = newnode;
    newnode->prev = NULL;
    *head = newnode;
}

void insertion_at_end(dll **head, int data)
{

    dll *newnode = new dll;
    dll *current = *head;
    newnode->data = data;
    newnode->next = NULL;

    while (current->next != NULL)
    {
        current = current->next;
    }

    newnode->prev = current;
    current->next = newnode;
}

void insertion_at_given(dll **head, int data, int pos)
{

    dll *newnode = new dll;
    dll *current = *head;
    dll *q;
    newnode->data = data;
    int k = 1;

    while (k != pos - 1)
    {
        current = current->next;
        k++;
    }
    q = current->next;
    current->next = newnode;
    newnode->prev = current;
    q->prev = newnode;
    newnode->next = q;
}

/*
Time Complexity: O(n). In the worst case, we may need to insert the node at the end of the list.
Space Complexity: O(1), for creating one temporary variable.
*/

int main()
{

    dll *head;

    dll *node1 = new dll;

    head = node1;
    node1->data = 1;
    node1->next = NULL;
    node1->prev = NULL;

    // cout << "As normal -> " << endl;
    // Traverse(head, 1);
    // cout << "As reverse -> " << endl;
    // Traverse(head, 0);

    // insert_at_begin(&head, 0);

    // cout << "As normal -> " << endl;
    // Traverse(head, 1);
    // cout << "As reverse -> " << endl;
    // Traverse(head, 0);

    insertion_at_end(&head, 2 ) ;
    insertion_at_end(&head, 3);

    // cout << "As normal -> " << endl;
    // Traverse(head, 1);
    // cout << "As reverse -> " << endl;
    // Traverse(head, 0);

    insertion_at_given(&head, 50 , 2);

    cout << "As normal -> " << endl;
    Traverse(head, 1);
    // cout << "As reverse -> " << endl;
    // Traverse(head, 0);

    return 0;
}