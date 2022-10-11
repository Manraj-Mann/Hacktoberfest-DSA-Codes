#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<int> x;
vector<vector<int>> adj;
int counter = 0;

void print(vector<int> &v)
{

    // cout << "\n---------------------------------\n";

    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // cout << "\n----------------------------------\n";
}
void nextvalue(int k)
{

    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {

            return;
        }
        int i = 0;
        for (i = 0; i < adj[k].size(); i++)
        {
            if (x[k] == x[adj[k][i]])
            {

                break;
            }
        }

        if (i == adj[k].size())
        {

            return;
        }
    }
}

void mcoloring(int k)
{
    while (k <= n)
    {
        //  cout<<"k = "<<k<<endl;

        nextvalue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            counter++;
            print(x);
        }
        else
        {

            mcoloring(k + 1);
        }

        // cout<<"returned for k = "<<k<<endl;
    }
}
int main()
{

    cin >> m;
    int e;
    cin >> n >> e;
    adj.resize(n + 1, vector<int>());
    x.resize(n + 1);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    mcoloring(1);
    cout << "Total number of solutions : " << counter << endl;

    return 0;
}