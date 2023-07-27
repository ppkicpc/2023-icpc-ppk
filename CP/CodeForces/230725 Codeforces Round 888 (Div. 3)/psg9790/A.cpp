#include <bits/stdc++.h>
using namespace std;

int T;

void solve()
{
    int result = 0;

    int n, m, k, H;
    cin >> n >> m >> k >> H;
    int acceptableDistance = k * (m - 1);

    vector<int> persons(n);
    for (int i = 0; i < n; i++)
    {
        cin >> persons[i];

        if (H == persons[i])
            continue;
        int diff = abs(persons[i] - H);
        if (diff > acceptableDistance)
            continue;
        if ((diff % k) != 0)
            continue;
        result++;
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
        solve();
}