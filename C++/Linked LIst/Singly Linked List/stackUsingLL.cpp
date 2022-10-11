#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LL
{
private:
    Node *head;

public:
    LL()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        if (!head)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        Node *ptr = new Node;
        if (!ptr)
        {
            return true;
        }
        delete ptr;
        return false;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "\nStack Overflow." << endl;
            return;
        }
        Node *ptr = new Node(val);
        ptr->next = head;
        head = ptr;
        cout << "\nNode with val " << val << " is Pushed into the Stack." << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow." << endl;
            return -1;
        }
        int val = head->data;
        Node *temp = head->next;
        delete head;
        head = temp;
        cout << "\nNode with val " << val << " is Popped from the Stack." << endl;
        return val;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow. \nNo elements present to display." << endl;
        }
        else
        {
            cout << "\nDisplaying all the elements of the Stack: " << endl;
            Node *ptr = head;
            while (ptr)
            {
                cout << "\t >> " << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }

    int stackTop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow." << endl;
            return -1;
        }
        else
        {
            cout << "\nNode's data at StackTop is: " << head->data << endl;
            return head->data;
        }
    }

    int stackBottom()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow." << endl;
            return -1;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next)
            {
                ptr = ptr->next;
            }
            cout << "\nNode's data at StackBOTTOM is: " << ptr->data << endl;
            return ptr->data;
        }
    }

    int count()
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty" << endl;
            return 0;
        }
        else
        {
            int counter = 1;
            Node *ptr = head;
            while (ptr->next)
            {
                counter++;
                ptr = ptr->next;
            }
            return counter;
        }
    }

    int peek(int val){
        if(isEmpty()){
            cout << "\nStack is Empty" << endl;
            return -1;
        }
        else{
            int pos=0, position=0;
            Node* ptr=head;
            while(ptr->next){
                pos++;
                if(ptr->data==val){
                    position=pos;
                    break;
                }
                ptr=ptr->next;
            }
            cout<<"\n" <<val <<" is present at Position: " <<position <<endl;
            return position;
        }
    }

    void change(int position, int val){
        if(isEmpty()){
            cout << "\nStack is Empty" << endl;
        }
        else{
            int pos=0;
            Node* ptr=head;
            while(ptr->next){
                pos++;
                if(pos==position){
                    ptr->data=val;
                    break;
                }
                ptr=ptr->next;
            }
            cout<<"\nValue changed at position " <<position <<" to: " <<val <<endl;
        }
    }

    void appendNode(int val){
        if(isEmpty()){
            head=new Node(val);
        }
        else{
            Node *ptr=head, *temp;
            while(ptr->next){
                ptr=ptr->next;
            }
            temp=new Node(val);
            ptr->next=temp;
        }
        cout<<"\nNode with value " <<val <<" is Appended." <<endl;
    }
};

int main()
{
    int val, op, pos;
    LL s1;
    while (1)
    {
        cout << "What operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl;
        cout << "10. Exit()" << endl;
        cout << "11. StackTop()" << endl;
        cout << "12. StackBottom()" << endl
             << endl;

        cin >> op;
        switch (op)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to push in the stack" << endl;
            cin >> val;
            s1.push(val);
            break;
        case 2:
            cout << "Pop Function Called - Poped val: " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            if (s1.isFull())
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;
        case 5:
            cout << "Enter the item whose index you want to peek: " << endl;
            cin >> val;
            cout << "Peek Function Called - val at position " << pos << " is " << s1.peek(pos) << endl;
            break;
        case 6:
            cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
            break;
        case 7:
            cout << "Change Function Called - " << endl;
            cout << "Enter position of item you want to change : ";
            cin >> pos;
            cout << endl;
            cout << "Enter val of item you want to change : ";
            cin >> val;
            s1.change(pos, val);
            break;
        case 8:
            cout << "Display Function Called - " << endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        case 10:
            exit(0);
        case 11:
            s1.stackTop();
            break;
        case 12:
            s1.stackBottom();
            break;
        default:
            cout << "Enter Proper op number b/w 1-12" << endl;
        }
    }

return 0;
}