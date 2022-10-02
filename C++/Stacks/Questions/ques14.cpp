// Given an array of elements, replace every element with nearest greater element
// on the right of that element.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextnearest(vector<int> &vec)
{

    vector<int> greatest(vec.size());                          
                                                                         
    stack<int> stk;

    for (int i = 0; i < vec.size(); i++)
    {
        if (stk.empty() == 1)
        {
            stk.push(i);
        }
        else
        {
            if (vec[stk.top()] > vec[i])
            {
                stk.push(i);
            }
            else
            {
                while ( stk.empty() != 1 &&vec[stk.top()] < vec[i])
                {
                    greatest[stk.top()] = vec[i];
                    stk.pop();
                }

                stk.push(i);
            }
        }
    }

    while (!stk.empty())
    {
        greatest[stk.top()] = vec[stk.top()];
        stk.pop();
    }
    

    return greatest;
}

void next_nearest(vector<int> &vec)
{

    int i = 0;
    stack<int> stk;

    stk.push(vec[0]);

    int element, nextnear;

    for (int i = 1; i < vec.size(); i++)
    {
        nextnear = vec[i];

        if (!stk.empty())
        {
            element = stk.top();
            stk.pop();

            while (element < nextnear)
            {
                cout << "for " << element << " next near : " << nextnear << " \n";
                if (stk.empty())
                {
                    break;
                }

                element = stk.top();
                stk.pop();
            }

            if (element > nextnear)
            {
                stk.push(element);
            }
        }

        stk.push(nextnear);
    }

    while (!stk.empty())
    {
        element = stk.top();
        stk.pop();
        nextnear = element;
        cout << "for " << element << " next near : " << nextnear << " \n";
    }
}

int main()
{

    vector<int> values = {6, 3, 4, 5, 2, 4, 4, 7};

    // ans - 7 4 5 7 4 7 7 7

    next_nearest(values);

    vector<int> res = nextnearest(values);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}