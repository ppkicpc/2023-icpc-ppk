#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<string> scheds;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        string token;
        cin >> token;
        scheds.push_back(token);
    }

    int stks = 0;
    int maxv = 0;
    for (int i = 0; i < d; i++)
    {
        bool isOpened = true;
        for (int j = 0; j < n; j++)
        {
            if (scheds[j][i] == 'x')
            {
                isOpened = false;
            }
        }

        if (isOpened)
        {
            stks++;
            maxv = max(maxv, stks);
        }
        else
        {
            stks = 0;
        }
    }
    cout << maxv << '\n';
}