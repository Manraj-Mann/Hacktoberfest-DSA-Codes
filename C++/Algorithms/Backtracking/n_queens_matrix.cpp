#include <bits/stdc++.h>
using namespace std;
vector<int> position;
bool placement(int k, int i)
{
    for (int j = 1; j <= (k - 1); j++)
    {
        if ((position[j] == i) || (abs(position[j] - i) == abs(j - k)))
            return false;
    }
    return true;
}

// void print(int n)
// {
//     cout << "[ ";
//     for (int i = 1; i <= n; i++)

//     {
//         cout << position[i] << " ";
//     }
//     cout << "]" << endl;
// }

void print(int n)
{

    for (int i = 1; i <= n; i++)

    {
        for (int j = 1; j <= n; j++)
        {
            if (position[i] == j)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void nqueens(int k, int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (placement(k, i))
        {
            position[k] = i;
            if (k == n)
            {
                print(n);
                cout << endl;
            }
            else
            {
                nqueens(k + 1, n);
            }
        }
    }
}

int main()
{
    cout << "Enter the value of n:";
    int n;
    cin >> n;
    position.resize(n + 1);

    nqueens(1, n);

    return 0;
}
