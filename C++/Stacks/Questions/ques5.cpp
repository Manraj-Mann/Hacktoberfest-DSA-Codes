// How to design a stack such that GetMinimum( ) should be O(1)?

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

    void resize()
    {
        int *arr_old = arr;
        arr = new int[2 * capacity];

        for (int i = 0; i <= capacity; i++)
        {
            arr[i] = arr_old[i];
        }

        capacity *= 2;

        delete[] arr_old;
    }
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[cap];

    }

    void create(int cap)
    {

        capacity = cap;
        arr = new int[cap];
 
    }

    void push(int data)
    {
        m_top++;
        if (isfull())
        {
            // cout<<"Resized\n";
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
            return CHAR_MAX;
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

    void print()
    {

        for (int i = 0; i <= m_top; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

};

class advancedstack{

    private:

    Stack * normalstack;
    Stack * minimum;

    public:

    advancedstack(int size){

        normalstack = new Stack(size);
        minimum = new Stack(size);
    }

    void push(int data){

        normalstack->push(data);
        if (minimum->isempty())
        {
            minimum->push(data);
        }
        else
        {
            if (minimum->top() > data)
            {
                minimum->push(data);
            }
            else
            {

                minimum->push(minimum->top());
            }
            
        }     
        
    }

    void pop(){

        normalstack->pop();
        minimum->pop();
    }

    int getmin(){

        return minimum->top();
    }

};
int main()
{
    int i = 1;
    advancedstack st(6);

    st.push(10);
    st.push(12);
    st.push(-1);
    st.push(-19);
    st.push(20);

    for (int i = 0; i < 4; i++)
    {
        cout<<st.getmin()<<endl;
        st.pop();
    }
    
}