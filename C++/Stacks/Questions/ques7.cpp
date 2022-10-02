// 1. Given an array of characters formed with a’s and b’s. The string is marked with
//  special character X which represents the middle of the list (for example:
//  ababa...ababXbabab baaa). Check whether the string is palindrome.

// 2. If the input is in singly linked list then how do we check whether
// the list elements form a palindrome (That means, moving backward is not possible).

#include <iostream>
using namespace std;

bool isplain(string str)
{

    int i = 0;
    int j = str.size() - 1;

    while (str[i] == str[j] && i < j)
    {
        i++;
        j--;
    }
    if (i < j)
    {
        return 0;
    }
    return 1;
}

int main()
{

    string a = "abababababababXbabababababa";

    std::cout << isplain(a) << endl;

    string b = "baXab";

    std::cout << isplain(b) << endl;


    // for list if make a stack of half the size if linkedlist
    // the push the elements till mid 
    // after that start poping as the elements keeps matching break if not
    // if the statck is empty at last means it palindrome 
    // else not





    return 0;
}