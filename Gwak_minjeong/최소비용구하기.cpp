#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;
int n, m;
int start, finish;
vector<pair<int, int> > bus[1001];

int cost[1001];

void dijk(){
    priority_queue <pair<int, int> > pq;
    
    

    pq.push(make_pair(0, start));
    cost[start]=0;

    while(!pq.empty()){
        
        int n_cost = -pq.top().first;//비용낮은순으로
        int n_node = pq.top().second;
        pq.pop();

        if(cost[n_node] >= n_cost){
            for(int i=0; i<bus[n_node].size(); i++) {
            int new_cost = n_cost + bus[n_node][i].second;

            if(new_cost < cost[bus[n_node][i].first]){
                cost[bus[n_node][i].first] = new_cost;
                pq.push(make_pair(-new_cost, bus[n_node][i].first));
            }
        }
        }

        
    }

    if(cost[finish] == INF) {
        cout << -1;
    }else{
        cout << cost[finish];
    }
    
}
int main(void) {
    cin>>n;
    cin>>m;
    int t1, t2, t3;
    for(int i=0; i<m; i++) {
        cin >> t1 >> t2 >> t3;

        bus[t1].push_back(make_pair(t2, t3));
        //bus[t2].push_back(make_pair(t1, t3));

    }
    cin>>start>>finish;

    fill(cost, cost+1001, INF);

    dijk();

    return 0;
}
