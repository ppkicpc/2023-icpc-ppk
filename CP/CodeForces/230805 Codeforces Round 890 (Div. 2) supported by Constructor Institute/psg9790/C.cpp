#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, k;
vector<int> arr;
int maxv = 0;
int maxIdx = -1;

bool Sweep(int idx)
{
    if (idx == 0)
        return;

    // 더 작은 블록들을 더 쌓을 수 있음
}

bool Build(int idx)
{
}

void solve()
{
    arr.clear();
    maxv = 0;
    maxIdx = -1;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;
        arr.push_back(token);
        if (token > maxv)
        {
            maxv = token;
            maxIdx = i;
        }
    }

    while (k)
    {
        // k가 허용하는 한

        // 아래 쓸어 내리기

        // 위 쌓아 올리기
    }

    cout << maxv << '\n';
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