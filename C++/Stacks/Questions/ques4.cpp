// Can we evaluate the infix expression with stacks in one pass?

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

    void push(char data)
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

// for binary operators
void procedure(Stack &operand, Stack &operator_)
{

    int num1 = (int)operand.pop() - '0';
    int num2 = (int)operand.pop() - '0';
    char opr = operator_.pop();

    int res;

    //cout<<"res = "<<num2<<" "<<opr<<" "<<num1<<endl;
    switch (opr)
    {
    case '+':
        res = num2 + num1;
        break;
    case '-':
        res = num2 - num1;
        break;
    case '*':
        res = num2 * num1;
        break;
    case '/':
        res = num2 / num1;
        break;
    }
    char r = res + '0';
    operand.push(r);
    //cout<<"pushed : "<<operand.top()<<endl;

}
int evaluate_infix(string &str)
{

    Stack operator_(str.size());
    Stack operand(str.size());

    for (int i = 0; i < str.size(); i++)
    {
        char next = str[i];

        if (!isoperator(next))
        {
            operand.push(next);
            //cout<<"pushed : "<<operand.top()<<endl;
        }
        else if(next == '('){

            operator_.push(next);
        }
        else if (next == ')')
        {
            while (operator_.top() != '(')
            {

                procedure(operand, operator_);
            }
            operator_.pop();
        }
        else
        {

            while ((operator_precedence(operator_.top()) > operator_precedence(next)) && operator_.isempty() != 1)
            {

                procedure(operand, operator_);
            }
            operator_.push(next);
        }
    }

    while (operator_.isempty() != 1)
    {
        procedure(operand, operator_);
    }

    return (int)operand.pop() - '0';
}

int main()
{

    // Using 2 stacks we can evaluate an infix expression in 1 pass without converting to
    // postfix.
    string str = "(1/(5-4+0))*(3-1)*4";

    cout << evaluate_infix(str);

    return 0;
}