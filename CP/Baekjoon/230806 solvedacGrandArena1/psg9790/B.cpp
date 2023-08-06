#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;

int n, m;
vector<string> words;
vector<string> options;
int qIdx;
set<string> ss;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        words.push_back(str);
        ss.insert(str);
        if (str == "?")
            qIdx = i;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string token;
        cin >> token;
        options.push_back(token);
    }

    if (words.size() == 1)
    {
        cout << options[0] << '\n';
        return;
    }

    for (int i = 0; i < options.size(); i++)
    {
        if (ss.find(options[i]) != ss.end())
            continue;
        char fst = options[i][0];
        char lst = options[i][options[i].length() - 1];
        // cout << fst << ' ' << lst << '\n';

        if (qIdx == 0)
        {
            char nxtFst = words[qIdx + 1][0];
            if (nxtFst == lst)
            {
                cout << options[i] << '\n';
                return;
            }
        }
        else if (qIdx == words.size() - 1)
        {
            char prevLast = words[qIdx - 1][words[qIdx - 1].length() - 1];
            if (prevLast == fst)
            {
                cout << options[i] << '\n';
                return;
            }
        }
        else
        {
            char nxtFst = words[qIdx + 1][0];
            char prevLast = words[qIdx - 1][words[qIdx - 1].length() - 1];
            // cout << nxtFst << ' ' << prevLast << '\n';
            if (fst == prevLast && lst == nxtFst)
            {
                cout << options[i] << '\n';
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    solve();
}