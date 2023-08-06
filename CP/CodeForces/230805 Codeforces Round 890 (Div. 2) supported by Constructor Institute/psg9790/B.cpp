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

    ll totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        arr.push_back(token);
        totalSum += token;
    }

    if (arr.size() == 1)
    {
        cout << "NO" << '\n';
        return;
    }

    ll oneSum = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            oneSum++;
        }
    }
    // cout << "oneSum " << oneSum << '\n';
    if (oneSum > totalSum)
    {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
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