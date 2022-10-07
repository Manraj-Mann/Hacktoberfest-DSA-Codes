#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include<conio.h>
using namespace std;
int *x;
int n;
int flag = 0;
bool Place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
        {
            return false;
        }
    }
    return true;
}
void write()
{
    flag++;
    cout << endl<<"Solution " << flag << "  ";
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == x[i])
            {
                cout << "Q"
                     << " | ";
            }
            else
            {
                cout << " "
                     << " | ";
            }
           
        }
         cout<<endl;
        for (int i = 0; i <n; i++)
        {
           cout << "_ _ " ;
        }
        cout<<endl;
        
        
    }
    for (int k = 1; k <= n; k++)
    {
        cout << x[k] << " ";
    }
}
void nqueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                write();
            }
            else
                nqueens(k + 1, n);
        }
    }
}
int main()
{
    cout << "Enter the size of nxn chessboard: ";
    cin >> n;
    x = new int[n + 1];
    x[0] = 0;
    double time_spent = 0.0;
    clock_t begin = clock();
    nqueens(1, n);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "No solution found" << endl;
    cout << "Execution Time : " << time_spent << " seconds" << endl;
    getch();
    return 0;
}
