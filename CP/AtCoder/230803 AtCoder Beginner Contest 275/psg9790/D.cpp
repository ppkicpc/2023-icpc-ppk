#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

ll n;
map<ll, ll> memo;

ll f(ll num)
{
    if (memo[num])
        return memo[num];
    memo[num] = f(num / 2) + f(num / 3);
    return memo[num];
}

void solve()
{
    memo[0] = 1;

    cin >> n;
    cout << f(n) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}