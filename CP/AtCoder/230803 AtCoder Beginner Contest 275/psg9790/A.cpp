#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
vector<ip> arr;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int token;
        cin >> token;
        arr.push_back({token, i});
    }
    sort(arr.begin(), arr.end(), [](ip a, ip b)
         { return a.first > b.first; });
    cout << arr.front().second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}