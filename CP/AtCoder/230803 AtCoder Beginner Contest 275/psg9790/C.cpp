#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

vector<vector<char>> arr;
vector<ip> pawns;

int hueDist(const ip &a, const ip &b)
{
    return abs(a.first - b.first - (a.second - b.second));
}

void solve()
{
    arr.resize(9);
    for (int i = 0; i < 9; i++)
    {
        string token;
        cin >> token;
        for (int j = 0; j < 9; j++)
        {
            arr[i].push_back(token[j]);
            if (token[j] == '#')
                pawns.push_back({i, j});
        }
    }

    int result = 0;
    for (int i = 0; i < pawns.size(); i++)
    {
        for (int j = i + 1; j < pawns.size(); j++) // pick two pawns
        {
            ip diff = {pawns[j].first - pawns[i].first, pawns[j].second - pawns[i].second};

            ip targetA_indent = {-diff.second, diff.first};
            ip targetB_indent = {diff.first + targetA_indent.first, diff.second + targetA_indent.second};
            // cout << targetA_indent.first << ',' << targetA_indent.second << ' ' << targetB_indent.first << ',' << targetB_indent.second << '\n';

            ip targetA = {pawns[i].first + targetA_indent.first, pawns[i].second + targetA_indent.second};
            ip targetB = {pawns[i].first + targetB_indent.first, pawns[i].second + targetB_indent.second};

            if (targetA.first >= 0 && targetA.first < 9 && targetA.second >= 0 && targetA.second < 9)
            {
                if (arr[targetA.first][targetA.second] != '#')
                    continue;
            }
            else
                continue;

            if (targetB.first >= 0 && targetB.first < 9 && targetB.second >= 0 && targetB.second < 9)
            {

                if (arr[targetB.first][targetB.second] != '#')
                    continue;
            }
            else
                continue;

            // cout << pawns[i].first << ',' << pawns[i].second << ' ' << pawns[j].first << ',' << pawns[j].second << '\n';
            // cout << pawns[i].first << ',' << pawns[i].second << ' ' << pawns[j].first << ',' << pawns[j].second << ' ' << targetA.first << ',' << targetA.second << ' ' << targetB.first << ',' << targetB.second << '\n';
            result++;
        }
    }
    cout << result / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}