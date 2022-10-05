/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;

        int l = 0, r = n-1 ;
        bool found = 0;

        while (l <= r)
        {

            int mid = l + (r - l) / 2;

            if (a[mid] == k)
            {
                found = 1;
                break;
            }
            else if (a[mid] < k)
            {

                l = mid + 1;
            }
            else
            {

                r = mid - 1;
            }
        }

        if (found)
        {
            cout << "YES\n";
        }
        else
        {

            cout << "NO\n";
        }
    }

    return 0;
}
