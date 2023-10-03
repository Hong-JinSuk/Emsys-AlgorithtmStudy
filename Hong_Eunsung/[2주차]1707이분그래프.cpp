#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int k, v, e, now, a, b, size, newV, qSize;
    bool bipartite;
    queue<int> bfsQ;
    vector<vector<int>> graph;
    vector<int> subset;
    cin >> k;

    for(int i = 0; i < k; i++){
        bipartite = true;
        cin >> v >> e;
        bfsQ = queue<int>();//bfs용 큐
        graph = vector<vector<int>>(v, vector<int>());//리스트 형태로 구현한 그래프
        subset = vector<int>(v, 0);//간선마다 1번집합인지 2번집합인지 표시해두기 위한 배열 
        for(int j = 0; j < e; j++){
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
      
        //v개의 노드에 대해서, for문 한번 돌리면서 미탐색 노드가 있으면 큐에 넣고 bfs실행.
        for(int x = 0; x < v; x++){
            if(subset[x]){//x번노드를 이미 탐색했을 경우 그냥 넘어간다.
                continue;
            }
            subset[x] = 1;
            bfsQ.push(x);

            while(!bfsQ.empty()){
                qSize = bfsQ.size();
                for(int j = 0; j < qSize; j++){//bfsQ의 모든 정점에 대해서
                    now = bfsQ.front();
                    size = graph[now].size();
                    for(int l = 0; l < size; l++){
                        newV = graph[now][l];//이번에 체크할 now의 인접정점
                        if(subset[now] == subset[newV]){//이분그래프가 아니면
                            bipartite = false;
                            break;
                        }
                        else if(!subset[newV]){//방문한 적 없는 정점이면 해당 정점의 subset을 설정하고 bfsQ에 넣는다
                            subset[newV] = (subset[now] % 2) + 1;
                            bfsQ.push(newV);
                        }
                        else{
                            continue;
                        }
                    }
                    if(!bipartite){
                        bfsQ = queue<int>();
                        break;
                    }
                    bfsQ.pop();
                }   
            }
        }
        //결과 출력
         if(bipartite){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
