#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;

void solve()
{
    cin >> n;
    int p1;
    cin >> p1;

    int maxv = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int token;
        cin >> token;
        maxv = max(maxv, token);
    }
    if (p1 <= maxv)
        cout << maxv - p1 + 1 << '\n';
    else
        cout << 0 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}