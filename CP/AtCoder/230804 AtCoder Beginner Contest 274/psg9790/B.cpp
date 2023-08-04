#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<int> arr;
void solve()
{
    cin >> n >> m;
    arr.assign(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        string token;
        cin >> token;
        for (int j = 1; j <= m; j++)
        {
            if (token[j - 1] == '#')
            {
                arr[j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}