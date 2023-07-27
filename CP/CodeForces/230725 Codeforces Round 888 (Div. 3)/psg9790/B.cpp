#include <bits/stdc++.h>
using namespace std;
using ip = pair<int, int>;

struct DecreaseOrder
{
    bool operator()(const ip &a, const ip &b)
    {
        return a.first > b.first;
    }
};

int T;
void solve()
{
    int n;
    cin >> n;

    deque<ip> evens;
    deque<ip> odds;
    vector<int> pattern;

    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;

        if (token % 2 == 0) // even
        {
            evens.push_back({token, i});
            pattern.push_back(0);
        }
        else // odd
        {
            odds.push_back({token, i});
            pattern.push_back(1);
        }
    }
    sort(evens.begin(), evens.end(), DecreaseOrder());
    sort(odds.begin(), odds.end(), DecreaseOrder());

    long lastv = -1;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (pattern[i] == 0) // even
        {
            int back = evens.back().first;
            evens.pop_back();
            if (back < lastv)
            {
                cout << "NO" << '\n';
                return;
            }
            lastv = back;
        }
        else // odd
        {
            int back = odds.back().first;
            odds.pop_back();
            if (back < lastv)
            {
                cout << "NO" << '\n';
                return;
            }
            lastv = back;
        }
    }
    cout << "YES" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
        solve();
}