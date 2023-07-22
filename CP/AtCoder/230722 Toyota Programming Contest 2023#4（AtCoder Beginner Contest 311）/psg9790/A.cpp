#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<bool> checked;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    checked.resize(3, false);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int token = s[i] - 'A';
        checked[token] = true;

        bool isFinished = true;
        for (int j = 0; j < 3; j++)
            if (!checked[j])
                isFinished = false;
        if (isFinished)
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}