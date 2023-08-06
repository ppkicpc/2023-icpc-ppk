#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

set<int> s;
void solve()
{
    int token;
    while (cin >> token)
    {
        set<int>::iterator _iter = s.find(token);
        if (_iter == s.end())
        {
            s.insert(token);
        }
        else
        {
            s.erase(token);
        }
    }
    for (auto i : s)
        cout << i << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}