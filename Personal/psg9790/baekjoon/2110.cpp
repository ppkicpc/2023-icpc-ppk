#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

ull n, m;
vector<ull> arr;

void solve()
{
    cin >> n >> m;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    vector<int> gyg;
    m -= 2;
    gyg.push_back(arr[0]);
    gyg.push_back(arr[arr.size() - 1]);
    int lower = arr[0];
    int upper = arr[arr.size() - 1];
    while (m != 0)
    {
        int mid = (upper - lower + 1) / (m + 1);
        vector<ull>::iterator iter = lower_bound(arr.begin(), arr.end(), mid);
        gyg.push_back(*iter);
        lower = *iter;
        m--;
    }

    sort(gyg.begin(), gyg.end());
    int result = 0;
    for (int i = 1; i < gyg.size(); i++)
        result = max(result, gyg[i] - gyg[i - 1]);
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}