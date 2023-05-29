#include <iostream>
#include <queue>
#include <vector>
#define INF 200000000
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<pair<int, int> > v[1001];
int dis[1001];
int st, en;

void djst() {
    pq.push(make_pair(0, st));
    dis[st] = 0;

    while (!pq.empty()) {
        int x = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > dis[x]) continue;

        for (auto next : v[x]) {
            int ncost = next.second;
            int nx = next.first;
            if (dis[nx] > ncost + cost) {
                dis[nx] = ncost + cost;
                pq.push(make_pair(ncost + cost, nx));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    fill(dis, dis + n+1, INF);
    while (m--) {
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s].push_back(make_pair(e, cost));
    }
    cin >> st >> en;
    djst();

    cout<< dis[en];
}
