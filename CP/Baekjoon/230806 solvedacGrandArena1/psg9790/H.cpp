#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m, q;
vector<int> row;
vector<int> column;
vector<vector<int>> arr;

void solve()
{
    cin >> n >> m >> q;
    row.assign(n + 1, 0);
    column.assign(m + 1, 0);

    for (int i = 0; i < q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) // row
            row[a] += b;
        else // column
            column[a] += b;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << row[i] + column[j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}