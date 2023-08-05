#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
map<int, int> _m;
vector<int> _v;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int token;
        cin >> token;
        if (_m.find(token) != _m.end())
        {
            _m[token]++;
        }
        else
        {
            _m[token] = 1;
            _v.push_back(token);
        }
    }
    sort(_v.begin(), _v.end());
    for (int i = 1; i <= n; i++)
    {
        if (((int)_v.size() - i) >= 0)
        {
            cout << _m[_v[_v.size() - i]] << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}