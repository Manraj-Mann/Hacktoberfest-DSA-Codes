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

        if (isfull())
        {
            std::cout << "Stack Overflow";
        }

        arr[++m_top] = data;
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
};

int main()
{

    Stack s;
    s.create(4);

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top();
    cout << s.pop();

    /*

    Space Complexity (for n push operations) O(n)
    Time Complexity of Push() O(1)
    Time Complexity of Pop() O(1)
    Time Complexity of Size() O(1)
    Time Complexity of IsEmptyStack() O(1)
    Time Complexity of IsFullStackf) O(1)
    Time Complexity of DeleteStackQ O(1)

    */

 /*
    The maximum size of the stack must first be defined and it cannot be changed. Trying to push a
    new element into a full stack causes an implementation-specific exception.
*/

    return 0;
}