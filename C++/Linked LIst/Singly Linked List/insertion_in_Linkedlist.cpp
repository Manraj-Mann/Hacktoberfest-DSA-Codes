#include <iostream>
using namespace std;
/*

• Inserting a new node before the head (at the beginning)
• Inserting a new node after the tail (at the end of the list)
• Inserting a new node at the middle of the list (random location)

*/

typedef struct LinkedList
{
    int data;
    LinkedList *next;

} List;

int Traverse(LinkedList *head)
{

    cout << "The data is : ";

    int count = 0;
    LinkedList *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
        count++;
    }
    return count;

    //   Time Complexity: O(n), for scanning the list of size n.
    //   Space Complexity: O(1), for creating a temporary variable.
}

// First Impementing All Seperately

void insert_at_begin(List **head, int data)
{

    List *newnode = new List;

    newnode->data = data;
    newnode->next = *head;

    *head = newnode;

    //   Time Complexity: O(1)
   // Space Complexity: O(1), for creating one temporary variable.
}

void insert_at_last(List **head, int data)
{

    LinkedList *current = *head;
    List *newnode = new List;

    newnode->data = data;
    newnode->next = NULL;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newnode;

    //   Time Complexity: O(n)
}

void insert_at_given(List **head, int pos, int data)
{
    LinkedList * current = *head;

    List *newnode = new List;
    newnode->data = data;
    int i = 1;
    while ( i != pos-1)
    {
        current = current->next;
        i++;
    }

    newnode->next = current->next;
    current->next = newnode;

    //   Time Complexity: O(n)
   // Space Complexity: O(1), for creating one temporary variable.

}


int main()
{

    List *head;

    List *node1 = new List;
    List *node2 = new List;

    head = node1;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = NULL;

    Traverse(head);
    cout << endl;

    insert_at_begin(&head, 0);

    Traverse(head);
    cout << endl;

    insert_at_last(&head, 100);
    Traverse(head);
    cout << endl;

    insert_at_given(&head, 3 ,50);
    Traverse(head);
    cout << endl;

    return 0;
}