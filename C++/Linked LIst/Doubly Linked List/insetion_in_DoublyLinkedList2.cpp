#include <iostream>
using namespace std;

typedef struct DoublyLinkedList
{
    int data;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;

} dll;
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

void insertion(dll **head, int data, int pos)
{

    dll *newnode = new dll;
    dll *current = *head;

    int k = 1;

    if (!newnode)
    {
        cout << "Memory no more !\n";
        return;
    }

    newnode->data = data;
    if (pos == 1)
    {

        newnode->next = *head;
        (*head)->prev = newnode;
        newnode->prev = NULL;
        *head = newnode;
    }
    else
    {
        current = *head;
        dll *q = (*head)->next;
        while (current->next != NULL && (k < pos))
        {

            current = current->next;
            q = current->next;
            k++;
            cout << k << endl;
        }

        // cout<<current->next->data<<endl;
        if (current->next == NULL)
        {
            cout << "last reached\n";
            newnode->next = NULL;
            newnode->prev = current;
            current->next = newnode;
            return;
        }

        cout << "No last reached\n";

        current->next = newnode;
        newnode->prev = current;
        q->prev = newnode;
        newnode->next = q;
    }
}

/*
Time Complexity: O(n). In the worst case, we may need to insert the node at the end of the list.
Space Complexity: O(1), for creating one temporary variable.
*/

int main()
{

    dll *head;

    dll *node1 = new dll;
    dll *node2 = new dll;

    head = node1;
    node1->data = 1;
    node1->next = node2;
    node1->prev = NULL;

    node2->data = 2;
    node2->next = NULL;
    node2->prev = node1;

    cout << "As normal -> " << endl;
    Traverse(head, 1);
    cout << "As reverse -> " << endl;
    Traverse(head, 0);

    insertion(&head, 0, 1); /// beginning

    cout << "As normal -> " << endl;
    Traverse(head, 1);
    cout << "As reverse -> " << endl;
    Traverse(head, 0);

    insertion(&head, 100, 2); /// any point

    cout << "As normal -> " << endl;
    Traverse(head, 1);
    cout << "As reverse -> " << endl;
    Traverse(head, 0);

    cout << "Started\n";
    insertion(&head, 50, 5); // at last

    cout << "As normal -> " << endl;
    Traverse(head, 1);
    cout << "As reverse -> " << endl;
    Traverse(head, 0);

    return 0;
}