#include <bits/stdc++.h>
using namespace std;

using ip = pair<int, int>;
int t;
int n, m, k;
ip vika;

bool diffNotOdd(ip a, ip b)
{
    int diff = abs(a.first - b.first);
    diff += abs(a.second - b.second);
    return ((diff % 2) == 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> k;
        int vx, vy;
        cin >> vx >> vy;
        vika = {vx, vy};
        string res = "YES";
        for (int j = 0; j < k; j++)
        {
            int fx, fy;
            cin >> fx >> fy;
            if (diffNotOdd(vika, {fx, fy}))
                res = "NO";
        }
        cout << res << '\n';

    EXIT:
        continue;
    }
}