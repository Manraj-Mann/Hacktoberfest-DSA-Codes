// Recursively remove all adjacent duplicates:

// Given a string of characters,
//  recursively remove adjacent duplicate characters from string. The output string should not
//  have any adjacent duplicates.

/*Input: careermonk
Output: camonk
Input: mississippi
Output: m*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeduplicates(string str)
{

    int i = 0;
    int len = str.size();
    std::string final_str = "";

    stack<char> stk;

    while (i < len)
    {
        stk.push(str[i]);
        //cout<<"pushed : "<<stk.top()<<endl;

        while (stk.empty() != 1)
        {
            char c = stk.top();
            stk.pop();

            if ( stk.empty() != 1 && stk.top() == c )
            {
               // cout<<"Matched "<<c<<endl;
                stk.pop();
            }
            else
            {
                stk.push(c);
                break;
            }
        }

        i++;
    }

    while (stk.empty() != 1)
    {
        final_str += stk.top();
        stk.pop();
    }

    std::reverse(final_str.begin() , final_str.end());
    

    return final_str;
}

int main()
{
    string res = removeduplicates("careermonk");
    cout<<(res)<<endl;
    string res2 = removeduplicates("mississippi");
    cout<<(res2)<<endl;

    return 0;
}