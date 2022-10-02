/*The array storing the stack elements may become full. A push operation will then throw a full
stack exception. Similarly, if we try deleting an element from an empty stack it will throw stack
empty exception*/

#include <iostream>
#include <climits>
using namespace std;

class Stack
{
private:
    int m_top = -1;
    int capacity;
    int *arr;

public:
    Stack() {}

    void resize(){

        int * arr_old = arr;
        arr = new int[2*capacity];
        
        for (int i = 0; i <= capacity ; i++)
        {
            arr[i] = arr_old[i];
        }

        capacity *= 2;

        delete [] arr_old;
        
    }
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[cap];
    }

    Stack *create(int cap)
    {

        capacity = cap;
        arr = new int[cap];
    }

    void push(int data)
    {
        m_top++;
        if (isfull())
        {
            //cout<<"Resized\n";
            resize();
        }

       // cout<<"Pushed "<<data<<endl;

        arr[m_top] = data;
    }
    int pop()
    {

        if (isempty())
        {
            std::cout << "Stack Underflow";
            return INT_MAX;
        }

        return arr[m_top--];
    }

    bool isfull()
    {

        if (m_top == capacity)
        {
            return true;
        }
        return false;
    }

    bool isempty()
    {

        if (m_top == -1)
        {
            return true;
        }
        return false;
    }

    void delete_stack()
    {

        delete[] arr;
    }

    int top()
    {

        return arr[m_top];
    }

    void print(){

        for (int i = 0; i <= m_top; i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
        
    }
};

int main()
{

    Stack s;
    s.create(1);

    s.push(1);
    s.push(2);
    s.push(3);

    s.print();

    
    s.push(4);
    s.push(5);
    s.push(6);

    s.print();
    
    cout << s.top()<<endl;
    s.pop();
    cout << s.top()<<endl;

    s.print();
    /*

Space Complexity (for n push operations) O(n)
Time Complexity of CreateStack() O(1)
Time Complexity of PushQ O(1) (Average)
Time Complexity of PopQ O(1)
Time Complexity of Top() O(1)
Time Complexity of IsEmpryStackf) O(1))
Time Complexity of IsFullStackf) O(1)
Time Complexity of DeleteStackQ O(1)

    */

    /*
       The maximum size of the stack must first be defined and it cannot be changed. Trying to push a
       new element into a full stack causes an implementation-specific exception.
   */

    return 0;
}