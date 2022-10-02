// Consider an empty stack of integers. Let the numbers 1,2,3,4,5,6 be pushed on to
// this stack in the order they appear from left to right. Let 5 indicate a push and X indicate a
// pop operation. Can they be permuted in to the order 325641(output) and order 154623?

#include <iostream>
#include <stack>
#include <vector>
// used stl stack

using namespace std;

string permutations(vector<int> &given, vector<int> &required)
{

    char s = 'S', x = 'X';

    stack<int> output;

    string result = "";
    int k = 0;

    for (int i = 0; i < given.size(); i++)
    {

        output.push(given[i]);
        result += s;
      //  cout << "pushed = " << given[i] << endl;
      //  cout << "result = " << result << endl;

        while ( output.empty() != 1 && output.top() == required[k])
        {
            result += x;
           // cout << "poped = " << output.top() << endl;
            output.pop();
            k++;
           // cout << "result = " << result << endl;
        }
    }

   // cout<<"out of loop\n";
    if (output.empty() == 1)
    {
        return result;
    }

    return "Not possible";
}

int main()
{

    vector<int> given;

    for (int i = 0; i < 6; i++)
    {
        given.push_back(i + 1);
    }

    vector<int> req = {3, 2, 5, 6, 4, 1};

    cout << permutations(given, req) << endl;

    vector<int> req2 = {1, 5, 4, 6, 2, 3};

    cout << permutations(given, req2) << endl;

    return 0;
}