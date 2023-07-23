#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &lines, const vector<int> &arr, vector<bool> &visited, vector<bool> &globalVisited, set<int> &result)
{
    lines.push_back(node);
    visited[node] = true;

    if (globalVisited[arr[node]]) // already visited, ignore previous members
    {
        for (vector<int>::iterator iter2 = --lines.end(); iter2 != --lines.begin(); iter2--)
        {
            globalVisited[(*iter2)] = true;
        }
        return;
    }

    if (visited[arr[node]]) //  cycle found
    {
        for (vector<int>::iterator iter = --lines.end(); iter != --lines.begin(); iter--) // add cycle members in result
        {
            result.insert((*iter));
            globalVisited[(*iter)] = true;
            if ((*iter) == arr[node])
            {
                for (vector<int>::iterator iter2 = next(iter, -1); iter2 != --lines.begin(); iter2--) // ignore non-cycle members
                {
                    globalVisited[(*iter2)] = true;
                }
                break; // cycle ends
            }
        }
        return;
    }
    dfs(arr[node], lines, arr, visited, globalVisited, result); // continue dfs
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<bool> globalVisited(n + 1, false);
    set<int> result;
    for (int i = 1; i <= n; i++)
    {
        if (!globalVisited[i]) // dfs start
        {
            vector<bool> visited(n + 1, false);
            vector<int> lines;
            dfs(i, lines, arr, visited, globalVisited, result);
        }
    }

    // total - cycle
    cout << n - result.size() << '\n';
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