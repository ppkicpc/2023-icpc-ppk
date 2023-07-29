#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

void stringOrder(string &_str, vector<ip> &_prefix, int lft, int rgt) // both inclusive
{
    ip rightPre = _prefix[rgt];
    ip leftPre = _prefix[lft - 1];
    ip onezero = {rightPre.first - leftPre.first, rightPre.second - leftPre.second};
    for (int i = lft - 1; i <= rgt - 1; i++)
    {
        if (onezero.second > 0)
        {
            onezero.second -= 1;
            _str[i] = '0';
            continue;
        }
        _str[i] = '1';
    }
}

ull hashCode(string &_str)
{
    const ull p = 53;
    const ull m = 1e9 + 9; // 10^9 + 9

    ull hash_val = 0;
    ull pow_p = 1;

    for (int i = 0; i < _str.length(); i++)
    {
        hash_val = (hash_val + (_str[i] - '0' + 1) * pow_p) % m;
        pow_p = (p * pow_p) % m;
    }
    return hash_val;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    string line;
    cin >> line;

    vector<ip> prefix(n + 1, {0, 0});
    for (int i = 1; i <= n; i++)
    {
        ip pre = prefix[i - 1];
        if (line[i - 1] == '1')
        {
            pre.first++;
            prefix[i] = pre;
        }
        else
        {
            pre.second++;
            prefix[i] = pre;
        }
    }

    string tokenString = line;
    set<ull> options;
    // options.insert(line);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        stringOrder(tokenString, prefix, l, r);
        int hash = hashCode(tokenString);
        // cout << "hash: " << hash << '\n';
        options.insert(hash);
        tokenString = line;
    }

    cout << options.size() << '\n';
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