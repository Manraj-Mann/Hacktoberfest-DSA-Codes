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

void delete_at_last(cll **head)
{

    cll *current = *head;
    cll *cur_prev;

    while (current->next != *head)
    {
        cur_prev = current;
        current = current->next;
    }

    cur_prev->next = *head;

    delete current;
}
void mod_delete_at_last(cll **head)
{

    if (*head == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else{
    
    cll *current = *head;
    cll *cur_prev;

    while (current->next != *head)
    {
        cur_prev = current;
        current = current->next;
    }

    cur_prev->next = *head;

    delete current;

    }
}

void delete_at_first(cll **head)
{

    cll *current = *head;
    cll *temp = *head;
    

    while (current->next != *head)
    {
       
        current = current->next;
    }

    current->next = (temp)->next;
    *head = (*head)->next;

    delete temp;
}
void mod_delete_at_first(cll **head)
{

    cll *current = *head;
    cll *temp = *head;
     if (*head == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    

    while (current->next != *head)
    {
       
        current = current->next;
    }

    current->next = (temp)->next;
    *head = (*head)->next;

    delete temp;
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

    mod_delete_at_last(&head);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;

    traverse(head);
    mod_delete_at_last(&head);
    traverse(head);
    delete_at_first(&head);

     traverse(head);

    return 0;
}