#include <vector>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int T, N;
vector<int> target = {202021, 20202021, 202002021, 202012021, 202022021, 202032021, 202042021, 202052021, 202062021, 202072021, 202082021, 202092021};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        long long cnt = 0;
        cin >> N;
        map<int, int> nmap;

        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            map<int, int>::iterator iter = nmap.find(a);
            if (iter != nmap.end())
                iter->second++;
            else
                nmap.insert({a, 1});
        }

        for (auto i : nmap)
        {
            for (int j = 11; j >= 0; j--)
            {
                int targetSize = target[j] - i.first;
                if (targetSize < i.first)
                    break;

                auto tgt = nmap.find(targetSize);
                if (tgt != nmap.end())
                {
                    cnt += (long long)tgt->second * nmap.find(i.first)->second;
                }
            }
        }

        cout << cnt << '\n';
    }
}