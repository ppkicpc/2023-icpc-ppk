#include <bits/stdc++.h>
using namespace std;

bool isWell(int num)
{
    return num == 202021 ||
           num == 20202021 ||
           num == 202002021 ||
           num == 202012021 ||
           num == 202022021 ||
           num == 202032021 ||
           num == 202042021 ||
           num == 202052021 ||
           num == 202062021 ||
           num == 202072021 ||
           num == 202082021 ||
           num == 202092021;
}
void solve()
{
    int n;
    long result = 0;
    map<int, int> nmap;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int token;
        cin >> token;

        auto iter = nmap.find(token);
        if (iter != nmap.end())
            iter->second++;
        else
            nmap.insert({token, 1});
    }

    for (map<int, int>::iterator iter1 = nmap.begin(); iter1 != nmap.end(); iter1++)
    {
        for (map<int, int>::iterator iter2 = next(iter1, 1); iter2 != nmap.end(); iter2++)
        {
            if (isWell(iter1->first + iter2->first))
            {
                result += (long)iter1->second * iter2->second;
            }
        }
    }

    cout << result << '\n';
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