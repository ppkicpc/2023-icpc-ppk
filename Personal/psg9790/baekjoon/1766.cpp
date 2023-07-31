#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void dfs(int idx)
{
    visited[idx] = true;

    sort(adj[idx].begin(), adj[idx].end(), [](int a, int b)
         { return a > b; });
    for (auto i : adj[idx])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    order.push_back(idx);
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = n; i > 0; i--)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());

    for (auto i : order)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
