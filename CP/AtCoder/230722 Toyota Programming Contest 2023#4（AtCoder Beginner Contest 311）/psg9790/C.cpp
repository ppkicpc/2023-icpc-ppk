#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> edges;
vector<int> result;

vector<bool> visited;
vector<int> dfsv;
void dfs(int i)
{
    visited[i] = true; // memorize
    dfsv.push_back(i);
    if (visited[edges[i]]) // already visited
    {
        for (vector<int>::iterator iter = --dfsv.end(); iter != (--dfsv.begin()); iter--) // trace back
        {
            result.push_back(*iter); // keep backward
            if ((*iter) == edges[i]) // loop finished
                break;
        }
        return;
    }
    dfs(edges[i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    edges.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        int token;
        cin >> token;
        edges[i] = token;
    }

    dfs(1);
    cout << result.size() << '\n';
    for (vector<int>::iterator iter = --result.end(); iter != (--result.begin()); iter--)
        cout << *iter << ' ';
}