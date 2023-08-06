#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<int> arr;
void solve()
{
    arr.clear();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        arr.push_back(token);
    }

    int maxv = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            maxv = max(maxv, arr[i - 1]);
        }
    }
    cout << maxv << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}