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
        return a->costUsed > b->costUsed;
    }
};

int n, t, m;
vector<vector<it3>> adj;
vector<int> costs;
void dijkstra(int start)
{
    priority_queue<Node *, vector<Node *>, NodeCmp> pq;
    pq.push(new Node(start, 0, 0));
    costs[start] = 0;

    while (!pq.empty())
    {
        Node *frt = pq.top();
        pq.pop();

        if (costs[frt->curNum] < frt->costUsed)
            continue;

        for (auto i : adj[frt->curNum])
        {
            int nextNum, nextTime, nextCost;
            tie(nextNum, nextTime, nextCost) = i;
            int targetTime = frt->timePassed + nextTime;
            if (targetTime > t)
                continue;
            int targetCost = frt->costUsed + nextCost;
            if (costs[nextNum] < targetCost)
                continue;
            costs[nextNum] = targetCost;
            pq.push(new Node(nextNum, targetTime, targetCost));
        }
    }

    if (costs[n] == INT_MAX)
        cout << -1 << '\n';
    else
        cout << costs[n] << '\n';
}

void solve()
{
    cin >> n >> t >> m;
    adj.resize(n + 1);
    costs.assign(n + 1, INT_MAX);

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