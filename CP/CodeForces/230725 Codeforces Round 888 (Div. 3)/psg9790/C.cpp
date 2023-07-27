#include <bits/stdc++.h>
using namespace std;

int t;

void solve()
{
    int n, k;

    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        arr.push_back(token);
    }

    int frt = arr[0];
    int bck = arr[arr.size() - 1];
    if (frt == bck) // find "k" elements "frt"
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == frt)
                cnt++;
            if (cnt >= k)
            {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    else
    {
        int frtCnt = k;
        int bckCnt = k;
        for (int i = 0; i < n; i++)
        {
            if (frtCnt > 0)
            {
                if (arr[i] == frt)
                {
                    frtCnt--;
                }
            }
            else
            {
                if (arr[i] == bck)
                {
                    bckCnt--;
                }
            }
        }
        if (frtCnt <= 0 && bckCnt <= 0)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
        solve();
}