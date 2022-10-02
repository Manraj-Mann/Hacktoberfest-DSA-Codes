// Largest rectangle under histogram: A histogram is a polygon composed of a
// sequence of rectangles aligned at a common base line. For simplicity, assume that the
// rectangles have equal widths but may have different heights. For example, the figure on the
// left shows a histogram that consists of rectangles with the heights 3,2,5,6,1,4,4, measured
// in units where 1 is the width of the rectangles. Here our problem is: given an array with
// heights of rectangles (assuming width is 1), we need to find the largest rectangle possible.
// For the given example, the largest rectangle is the shared part.

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <string>
using namespace std;

int maxar(vector<int> &vec){

    int max , maxar = INT_MIN  , left , top;

    stack<int> stk;

    for (int i = 0; i < vec.size(); i++)
    {
        cout<<" i = "<<i<<endl;

        while ( i < vec.size() &&((stk.empty() == 1) || vec[stk.top()] <= vec[i])) 
        {
            left = i;
            stk.push(i);
            cout<<"pushed : "<<vec[stk.top()]<<endl;
            i++;
        }

        int h =  vec[stk.top()];
        stk.pop();
        if (!stk.empty())
        {
            left = stk.top();
            max = (i - left - 1) * h;
        }
        else{

            left = 0;
            max = (i - left) * h;
        }


        cout<<"new area : "<<max<<endl;

        cout<<"-------------------------------------\n";

        if(maxar < max){

            maxar = max;
        }

        i--;
        
    }

    return maxar;
    


}

int main()
{

    vector<int> n = {3,1,5,6,2,3};
    vector<int> n2 = {3,1,5,6,4 , 4};

    cout<<maxar(n)<<endl;
    cout<<maxar(n2)<<endl;

    return 0;
}