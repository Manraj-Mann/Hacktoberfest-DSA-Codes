// Finding Spans: Given an array A, the span S[i] of A[i] is the maximum number
// of consecutive elements A[j] immediately preceding A[i] and such that A[j] < A[i]?
// Other way of asking: Given an array A of integers, find the maximum of j – i subjected to
// the constraint of A[i] < A[j].

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print(vector<int> &vec)
{

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
vector<int> naive_soln(vector<int> &vec)
{

    vector<int> result;

    for (int i = 0; i < vec.size(); i++)
    {
        int j = 1;

        while (j <= i && vec[i] > vec[i - j])
        {
            j++;
        }

        result.push_back(j);
    }

    return result;
}
vector<int> stack_impt(vector<int> &vec)
{

    vector<int> result;
    stack<int> d;

    int p;

    for (int i = 0; i < vec.size(); i++)
    {
        while ((!d.empty()) && vec[i] > vec[d.top()])
        {
            d.pop();
        }

        if (d.empty())
        {
            p = -1;
        }
        else
        {
            p = d.top();
        }

        result.push_back(i - p);

        d.push(i);
    }

    return result;
}

int main()
{

    vector<int> values = {6, 3, 4, 5, 2};

    vector<int> r = naive_soln(values);
    print(r);

    // Time Complexity: O(n2). Space Complexity: O(1).

    vector<int> r2 = stack_impt(values);
    print(r2);
    
    // Time Complexity: O(n). Space Complexity: O(n).

    return 0;
}
