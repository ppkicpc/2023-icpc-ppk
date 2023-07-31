#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using it3 = tuple<int, int, int>;

class Node
{
public:
    Node(int _curNum, int _timePassed, int _costUsed) : curNum(_curNum), timePassed(_timePassed), costUsed(_costUsed) {}
    int curNum;
    int timePassed;
    int costUsed;
};
struct NodeCmp
{
    bool operator()(const Node *a, const Node *b)
    {
        if (a->costUsed == b->costUsed)
            return a->timePassed > b->timePassed;
        return a->costUsed > b->costUsed;
    }
};

int n, t, m;
vector<vector<it3>> adj;
vector<int> costs;
vector<int> times;

void dijkstra(int start)
{
    int result = INT_MAX;

    priority_queue<Node *, vector<Node *>, NodeCmp> pq;

    Node *init = new Node(start, 0, 0);
    pq.push(init);

    while (!pq.empty())
    {
        Node *frt = pq.top();
        pq.pop();
        if (frt->timePassed > t) // time overflow
            continue;
        if (frt->timePassed > times[frt->curNum] && frt->costUsed > costs[frt->curNum])
            continue;
        if (frt->curNum == n) // denote result
            result = min(result, frt->costUsed);

        for (auto u : adj[frt->curNum])
        {
            int nextNum = get<0>(u), nextTime = get<1>(u), nextCost = get<2>(u);
            int targetTime = frt->timePassed + nextTime;
            int targetCost = frt->costUsed + nextCost;

            if (targetTime > times[nextNum] && targetCost > costs[nextNum])
                continue;
            else if (targetTime < times[nextNum] && targetCost < costs[nextNum])
            {
                times[nextNum] = targetTime;
                costs[nextNum] = targetCost;
            }
            pq.push(new Node(nextNum, targetTime, targetCost));
        }
    }
    cout << result << '\n';
}

void solve()
{
    cin >> n >> t >> m;
    adj.resize(n + 1);
    costs.assign(n + 1, INT_MAX);
    times.assign(n + 1, INT_MAX);

    int l;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int a, b, minute, cost;
        cin >> a >> b >> minute >> cost;
        adj[a].push_back(tie(b, minute, cost));
        adj[b].push_back(tie(a, minute, cost));
    }
    dijkstra(1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}