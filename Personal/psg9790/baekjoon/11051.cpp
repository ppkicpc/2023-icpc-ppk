#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

vector<ull> dp;
int n, k;

void solve()
{
    cin >> n >> k;
    int lower = (dp[k] * dp[n - k]);
    cout << (dp[n] / lower) % 10007 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp.assign(1001, 1);
    for (int i = 2; i <= 1000; i++)
        dp[i] = (i * dp[i - 1]);

    solve();
}
