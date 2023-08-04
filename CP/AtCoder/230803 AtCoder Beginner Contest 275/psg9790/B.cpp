#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

ull MOD = 998'244'353;
ull a, b, c, d, e, f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d >> e >> f;
    a %= MOD;
    b %= MOD;
    c %= MOD;
    d %= MOD;
    e %= MOD;
    f %= MOD;

    ull aVal = (a * b) % MOD;
    aVal = (aVal * c) % MOD;
    ull bVal = (d * e) % MOD;
    bVal = (bVal * f) % MOD;
    cout << (aVal - bVal + MOD) % MOD << '\n';
}