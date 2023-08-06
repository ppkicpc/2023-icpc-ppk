#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<vector<int>> adj_rev;
vector<int> parent;

int dfs(int idx)
{
    for (auto u : adj_rev[idx])
        return parent[idx] = dfs(u);
    return idx;
}

void solve()
{
    cin >> n >> m;
    parent.resize(n + 1);
    adj_rev.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_rev[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        dfs(i);
    for (int i = 1; i < n; i++)
    {
        if (parent[i] != parent[i + 1])
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << parent[1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}