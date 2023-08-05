#include <bits/stdc++.h>
// #include <windows.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

double x;
int k;

void solve()
{
    // cin >> x >> k;
    x = rand();
    k = rand() % 14 + 1;
    cout << "-----\n";
    cout << x << ' ' << k << '\n';

    ll pow = 10;
    for (int i = 1; i <= k; i++)
    {
        // cout << x << '\n';
        x /= pow;
        // cout << x << '\n';

        x = round(x);
        x *= pow;

        pow *= 10;
    }

    cout << fixed;
    cout.precision(0);
    cout << x << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 15;
    srand(time(0));

    while (t--)
        solve();
}