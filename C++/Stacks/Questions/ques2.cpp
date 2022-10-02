// Discuss infix to postfix conversion algorithm using stack

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

int operator_precedence(char c)
{

    if (c == '*')
    {
        return 3;
    }
    else if (c == '+')
    {

        return 1;
    }
    else if (c == '-')
    {

        return 2;
    }
    else if (c == '/')
    {

        return 4;
    }
    else if (c == '(')
    {

        return 0;
    }
}

bool isoperator(char c)
{

    if (c == '*' || c == '-' || c == '+' || c == '/' || c == '(' || c == ')')
    {
        return 1;
    }
    return 0;
}

string infix_to_postfix(string &str)
{

    Stack s(str.size());

    string result = "";

    for (int i = 0; i < str.size(); i++)
    {

        if (isoperator(str[i]))
        {
            if (s.isempty() == 1)
            {
                s.push(str[i]);
            }
            else if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else
            {

                if (str[i] == ')')
                {
                    while (s.top() != '(')
                    {
                        result += s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else if (operator_precedence(s.top()) < operator_precedence(str[i]))
                {
                    s.push(str[i]);
                }
                else
                {

                    while ((operator_precedence(s.top()) > operator_precedence(str[i]) ) && s.isempty() != 1)
                    {
                        result += s.top();
                        s.pop();
                    }

                    s.push(str[i]);
                }
            }
        }
        else
        {

            result += str[i];
        }
    }

    while (s.isempty() != 1)
    {
        result += s.top();
        s.pop();
    }

    return result;
}

int main()
{

    string str = "A*B-(C+D)+E";

    cout << "Postfix = " << infix_to_postfix(str);
    return 0;
}