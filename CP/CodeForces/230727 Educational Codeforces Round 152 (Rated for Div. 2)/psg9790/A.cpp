#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int inner = m + k;
    int outer = min(m + k + 1, n);
    cout << 2 * outer - 1 << '\n';
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