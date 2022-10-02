#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *next;
} cll;
void traverse(cll *head)
{
    cout << "The list contains : ";

    cll *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;

    } while (current != head);
    cout << endl;
}

// Impementation Individually

void insert_at_end(cll **head, int data)
{

    cll *newnode = new cll;
    newnode->data = data;
    cll *current = *head;

    do
    {
        current = current->next;
    } while (current->next != *head);

    current->next = newnode;
    newnode->next = *head;
}
void mod_insert_at_end(cll **head, int data)
{

    cll *newnode = new cll;

    if (!newnode)
    {
        cout << "Memory error\n";
        return;
    }

    newnode->data = data;
    newnode->next = newnode;
    cll *current = *head;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    else
    {

        do
        {
            current = current->next;
        } while (current->next != *head);

        current->next = newnode;
        newnode->next = *head;
    }
}

void insert_at_first(cll **head, int data)
{

    cll *current = *head;
    cll *newnode = new cll;

    newnode->data = data;
    newnode->next = *head;

    do
    {
        current = current->next;
    } while (current->next != *head);

    current->next = newnode;

    *head = newnode;
}

void mod_insert_at_first(cll **head, int data)
{

    cll *current = *head;
    cll *newnode = new cll;

    if (!newnode)
    {
        cout << "Memory error\n";
        return;
    }

    newnode->data = data;
    newnode->next = newnode;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {

        do
        {
            current = current->next;
        } while (current->next != *head);

        newnode->next = *head;
        current->next = newnode;

        *head = newnode;
    }
}

int main()
{
    cll *head = NULL;
    cll *node1, *node2, *node3, *node4, *node5;

    node1 = new cll;
    node2 = new cll;
    node3 = new cll;
    node4 = new cll;
    node5 = new cll;

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;

    mod_insert_at_first(&head, 100);

    mod_insert_at_end(&head, 10);

    traverse(head);

    //   head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;

    traverse(head);

    insert_at_end(&head, 6);

    mod_insert_at_end(&head, 7);

    traverse(head);

    insert_at_first(&head, 200);

    traverse(head);
    return 0;
}