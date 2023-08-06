#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n;
deque<ll> arr;

void solve()
{
    arr.clear();

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        if (arr.size() == 0)
        {
            arr.push_back(val);
            continue;
        }

        if (val < 0) // neg
        {
            if (arr.back() < 0)
                arr[arr.size() - 1] += val;
            else
                arr.push_back(val);
        }
        else // pos
        {
            arr.push_back(val);
        }
    }
    for (auto u : arr)
        cout << u << ' ';
    cout << '\n';

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            if (i > 0) // 이전 비교 가능
            {
                if (i < arr.size() - 1) // 이후 비교 가능
                {
                    // 둘다 비교
                    if (arr[i - 1] <= 0 && arr[i + 1] <= 0)
                    {
                    }
                    else if (arr[i - 1] <= 0)
                    {
                    }
                    else if (arr[i + 1 <= 0])
                    {
                    }
                }
                else
                {
                    // 이전 것만 비교
                    if (arr[i - 1] <= 0 && arr[i - 1] + arr[i] >= 0)
                    {
                        arr[i] += arr[i - 1];
                        arr.erase(next(arr.begin(), i - 1));
                    }
                }
            }
            else // 이전 비교 불가
            {
                if (arr[i + 1] <= 0 && arr[i + 1] + arr[i] >= 0) // 다음 비교
                {
                    arr[i] += arr[i + 1];
                    arr.erase(next(arr.begin(), i + 1));
                }
            }
        }
    }
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