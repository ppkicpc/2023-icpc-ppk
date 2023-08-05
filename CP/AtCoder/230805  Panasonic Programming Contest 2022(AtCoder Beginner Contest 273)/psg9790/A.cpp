#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;

int recursive(int num)
{
    if (num == 0)
        return 1;
    return recursive(num - 1) * num;
}

void solve()
{
    cin >> n;
    cout << recursive(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}