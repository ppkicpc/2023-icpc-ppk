#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<int> memo;

void solve()
{
    cin >> n;

    memo.push_back(0);
    cout << 0 << '\n';
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;

        vector<int>::iterator iter = lower_bound(memo.begin(), memo.end(), token);

        cout << (iter - memo.begin()) << '\n';
        cout << (iter - memo.begin()) << '\n';

        memo.insert(iter, token);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}