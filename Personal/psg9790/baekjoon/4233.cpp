#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

ull p, a, pp, aa;

ull fpow()
{
    ull res = 1;
    while (p)
    {
        if (p & 1)
            res *= a;
        a *= a;
        p /= 2;

        a %= pp;
        res %= pp;
    }
    return res;
}

void solve()
{
    while (true)
    {
        cin >> p >> a;
        pp = p;
        aa = a;
        if (p == 0 && a == 0)
            break;

        ull res = fpow();

        // if () // if p is not prime
        {
            if (res == aa)
            {
                cout << "yes" << '\n';
                continue;
            }
        }
        cout << "no" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}