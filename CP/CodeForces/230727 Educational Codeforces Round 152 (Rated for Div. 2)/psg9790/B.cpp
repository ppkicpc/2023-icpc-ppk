#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

struct monstersCmp
{
    bool operator()(const ip &a, const ip &b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ip> monsters;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        int newToken = token % k;
        if (newToken == 0)
            newToken = k;
        monsters.push_back({newToken, i});
    }
    sort(monsters.begin(), monsters.end(), monstersCmp());

    for (auto i : monsters)
        cout << i.second + 1 << ' ';
    cout << '\n';
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