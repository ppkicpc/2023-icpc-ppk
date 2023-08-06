#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int MOD = 1e9 + 7;

int n, k;
vector<int> arr;
set<int> ss;

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        arr.push_back(token);
        ss.insert(token);
    }
    sort(arr.begin(), arr.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}