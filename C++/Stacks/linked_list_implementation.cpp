#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class stack
{

private:
    node *head;
    node *current; // top

public:
    stack()
    {

        current = NULL;
        head = NULL;
    }

    void push(int data)
    {

        node *newnode = new node;
        newnode->data = data;

        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    bool isempty()
    {

        if (head == NULL)
        {
            return 1;
        }

        return 0;
    }

    void pop()
    {
        node *todelete = head;
        head = head->next;
        delete todelete;
    }

    int top (){

        return head->data;
    }

    void delete_stack(){

        while (head != NULL)
        {
            node * todel = head;
            head = head->next;
            delete todel;
        }
        
    }

    void print(){

        node * ptr = head;

        while (ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }

        cout<<endl;
    }
};

int main()
{

    stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.print();

    s.push(4);
    s.push(5);
    s.push(6);

    s.print();

    s.pop();

    s.print();

    cout<<s.top();


    /*

    Space Complexity (for n push operations) O(n)
    Time Complexity of CreateStack() O(1)
    Time Complexity of Push() O(1) (Average)
    Time Complexity of Pop() O(1)
    Time Complexity of Top() O(1)
    Time Complexity of IsEmptyStack() O(1)
    Time Complexity of DeleteStack() O(n)

    */

    return 0;
}