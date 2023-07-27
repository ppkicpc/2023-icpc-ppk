#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> inputs(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<ll> remained;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> inputs[i];
        ll diff = inputs[i] - inputs[i - 1];
        if (diff <= n)
        {
            if (!visited[diff])
            {
                visited[diff] = true;
            }
            else
            {
                remained.push_back(diff);
            }
        }
        else
        {
            remained.push_back(diff);
        }
    }

    if (remained.size() == 0)
    {
        cout << "YES" << '\n';
        return;
    }
    else if (remained.size() > 1)
    {
        cout << "NO" << '\n';
        return;
    }

    ll sumv = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            sumv += i;
        }
    }

    if (sumv != remained[0])
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