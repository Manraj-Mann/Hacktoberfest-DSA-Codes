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
}

/*

• Deleting the first node
• Deleting the last node
• Deleting an intermediate node.

*/

void delete_node(List **head, int pos)
{

    int k = 1;

    if (*head == NULL)
    {
        cout << "List is Empty\n";
    }

    List *current = *head;
    List *q;

    if (pos == 1)
    {
        *head = (*head)->next;
        delete current;
        return;
    }
    else
    {

        while ((current != NULL) && k < pos)
        {
            q = current;
            current = current->next;
            k++;
        }
        if (current == NULL)
        {
            cout << "No such position\n";
        }
        else
        {

            q->next = current->next;
            delete current;
        }
    }
}

//   Time Complexity: O(n), for scanning the list of size n.
//   Space Complexity: O(1), for creating a temporary variable.

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
    delete_node(&head, 1);
    Traverse(head);
    cout << endl;
    delete_node(&head, 3);
    Traverse(head);
    cout << endl;

    delete_node(&head, 3);
    Traverse(head);
    cout << endl;

    return 0;
}