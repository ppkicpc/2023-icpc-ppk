#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> price(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < k; i++)
    {
        int token;
        cin >> token;
        price[token] = 0;
    }

    vector<vector<int>> options(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int _requires;
            cin >> _requires;
            options[i].push_back(_requires);
        }
    }

    while (true)
    {
        bool _changed = false;

        for (int i = 1; i <= n; i++)
        {
            if (options[i].size() == 0)
                continue;
            int creationPrice = 0;
            for (int j = 0; j < options[i].size(); j++)
            {
                creationPrice += price[options[i][j]];
            }
            if (price[i] > creationPrice)
            {
                _changed = true;
                price[i] = creationPrice;
            }
        }

        if (!_changed)
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << price[i] << ' ';
    }
    cout << '\n';
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