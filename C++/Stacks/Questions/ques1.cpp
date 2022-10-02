// Discuss how stacks can be used for checking balancing of symbols.

#include <iostream>
#include <climits>
using namespace std;

class Stack
{
private:
    int m_top = -1;
    int capacity;
    char *arr;

public:
    Stack() {}

    void resize()
    
    {

        char *arr_old = arr;
        arr = new char[2 * capacity];

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
        arr = new char[cap];
    }

    Stack *create(int cap)
    {

        capacity = cap;
        arr = new char[cap];
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
    char pop()
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

    char top()
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

int check_paren(string &str)
{

    Stack s(str.size());

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }

        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (s.isempty() == 1 )
            {
                return i;
            }
            else if((str[i] == ')' && s.top()=='(') ||(str[i] == '}' && s.top() =='{' )|| ( str[i] == ']' && s.top()== '[')){

                s.pop();

            }
            else 
            {
                return i;
            }
        }
    }

    if (s.isempty() != 1)
    {
        return 0;
    }


    return INT_MAX;
}

int main()
{

    string str;
   // std::cin >> str;

    //str = "(A+B)+(C-D)";
    // str = "((A+B)+(C+D)";
    // str = "((A+B)+[C-D])";
    str = "((A+B)+[C-D]}";

    int n = check_paren(str);
    if (n == INT_MAX)
    {
        std::cout << "Balanced\n";
    }
    else
    {

        std::cout << "UNBALANCED \n";
    }

    return 0;
}

//Time Complexity: O(n). Since we are scanning the input only once. Space Complexity: O(n) [for stack].