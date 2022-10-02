#include <iostream>
using namespace std;

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

/*

• Deleting the first node
• Deleting the last node
• Deleting an intermediate node.

*/


// Implementation individually

void delete_at_first(List **head)
{

    List *temp;

    temp = *head;
    *head = (*head)->next;

    //  delete temp->next;
    delete temp;

    //  Time Complexity: O(1), for scanning the list of size n.
}

void delete_at_last(List **head)
{

    List *current = (*head)->next;
    List *previous = *head;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    delete current;

    //  Time Complexity: O(n), for scanning the list of size n.
}

void delete_at_given(List **head, int pos)
{

    List *current = (*head)->next;
    List *previous = *head;

    int k = 1;
    while (k != pos - 1)
    {
        previous = current;
        current = current->next;
        k++;
    }

    previous->next = current->next;
    delete current;
}

int main()
{

    List *head;

    List *node1 = new List;
    List *node2 = new List;
    List *node3 = new List;
    List *node4 = new List;
    List *node5 = new List;

    head = node1;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = node5;

    node5->data = 5;
    node5->next = NULL;

    Traverse(head);
    cout << endl;

    delete_at_first(&head);
    Traverse(head);
    cout << endl;

    delete_at_last(&head);
    Traverse(head);
    cout << endl;

    delete_at_given(&head, 2);
    Traverse(head);
    cout << endl;

    return 0;
}