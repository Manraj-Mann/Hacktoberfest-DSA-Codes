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
void insert(List **head, int data, int position)
{

    int k = 1;

    List *newnode = new List;

    if (!newnode)
    {
        cout << "Memory Error\n";
        return;
    }

    newnode->data = data;

    List *current = *head;

    // At beginning

    if (position == 1)
    {
        newnode->next = current;
        *head = newnode;
    }
    else
    {

        // Traverse until we want to position to insert

        while ((current != NULL) && (k != position-1))
        {
            k++;
            current = current->next;
        }

    
        newnode->next = current->next;
        current->next = newnode;
    }
}
//   Time Complexity: O(n)
//   Space Complexity: O(1), for creating one temporary variable.

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

    insert(&head, 0, 1);
    Traverse(head);
    cout << endl;

    insert(&head, 50, 3);
    Traverse(head);
    cout << endl;

    insert(&head, 100, 5);
    Traverse(head);
    cout << endl;

    return 0;
}