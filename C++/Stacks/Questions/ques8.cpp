// How do we implement two stacks using only one array? Our stack routines
// should not indicate an exception unless every slot in the array is used?

#include <iostream>
#include <climits>
using namespace std;

class Stack
{
private:
    int m_top1= -1;
    int m_top2;
    int capacity;
    int *arr;

public:
    Stack() {}

    Stack(int cap)
    {
        capacity = cap;
        arr = new int[cap];
        m_top2 = cap;
    }

    Stack *create(int cap)
    {

        capacity = cap;
        arr = new int[cap];
    }

    void pushleft(int data)
    {
        m_top1++;
        if (isfull())
        {
             cout<<"Overflow\n";
             m_top1--;
            
        }

        // cout<<"Pushed "<<data<<endl;
        arr[m_top1] = data;
    }
    void pushright(int data)
    {
        m_top2--;
        if (isfull())
        {
            cout<<"Overflow\n";
            m_top2--;
            
        }

        // cout<<"Pushed "<<data<<endl;
        arr[m_top2] = data;
    }
    int popleft()
    {

        if (isemptyleft())
        {
            std::cout << "Stack Underflow";
            return CHAR_MAX;
        }

        return arr[m_top1--];
    }
    int popright()
    {

        if (isemptyright())
        {
            std::cout << "Stack Underflow";
            return CHAR_MAX;
        }

        return arr[m_top2++];
    }

    bool isfull()
    {

        if (m_top1 == m_top2)
        {
            return true;
        }
        return false;
    }

    bool isemptyleft()
    {

        if (m_top1 == -1)
        {
            return true;
        }
        return false;
    }
    bool isemptyright()
    {

        if (m_top2 == -1)
        {
            return true;
        }
        return false;
    }

    void delete_stack()
    {

        delete[] arr;
    }

    int topleft()
    {

        return arr[m_top1];
    }
    int topright()
    {

        return arr[m_top2];
    }


};


int main(){

    Stack st(10);

    st.pushleft(1);
    st.pushleft(2);
    st.pushleft(3);
    st.pushleft(4);
    st.pushleft(5);

    st.pushright(10);
    st.pushright(9);
    st.pushright(8);
    st.pushright(7);
    st.pushright(6);


    st.pushright(6);
    st.popright();
    st.pushright(6);
    

return 0;
}