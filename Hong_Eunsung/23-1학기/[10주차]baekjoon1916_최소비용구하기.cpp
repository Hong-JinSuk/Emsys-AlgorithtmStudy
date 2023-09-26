#include<iostream>
#include<vector>
#include<limits.h>//MAX_INT 쓰려고 가져온거
using namespace std;
vector<vector<pair<int, int>>> graph(1000);//목적지, 거리 순으로 저장하는 인접리스트 형식의 그래프
vector<bool> visited(1000, 0); //방문기록 
vector<int>dist(1000, INT_MAX); //시작도시에서 각 도시로 이동하기 위해 드는 비용을 저장하는 일차원 배열

int newStart(int n) {//다음번 다익스트라를 수행할 도시를 찾아내서 반환해주는 함수
	//초기 오답 이유 : dist가 최소이면서 방문 안 한 노드를 newnode로 해야 하는데, 현재 위치에서 가장 가까운 곳으로 newnode를 계속 갱신해줘서.
	//결국 start에서 dest까지의 최단경로를 구하는 게 핵심이므로, 다익스트라도 start에서 가까운 순으로 진행해야 한다.
	int newnode = -1, min = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (!visited[i] && dist[i] < min) {//방문한 적 없는 도시 중, 시작지점에서 최소비용으로 갈 수 있는 도시를 찾는다.
			newnode = i; min = dist[i];
		}
	}

	if (newnode != -1) //만약 갈 수 있는 도시가 있다면
		visited[newnode] = true; //해당 도시에 방문표시를 해두고
	return newnode;//갈 수 있는 도시가 없으면 -1, 있으면 해당 도시 번호를 반환
}

void dijkstra(int start) { //메인함수의 start 도시로부터, 현재 탐색중인 도시와 인접한 모든 도시까지의 거리를 dist에 갱신해주는 함수
	int size = graph[start].size(); //현재 탐색중인 도시와 인접한 도시의 개수
	int dest;
	for (int i = 0; i < size; i++) { //현재 탐색중인 도시로부터 인접한 모든 도시에 대해서
		dest = graph[start][i].first;
		dist[dest] = min(dist[dest], dist[start] + graph[start][i].second); //[main의 start로부터 거기까지의 거리 / 현재 도시를 경유하여 가는 거리] 비교해서 dist에 더 작은 값 갱신
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, start, dest, cost, now;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> start >> dest >> cost;
		graph[start - 1].push_back({ dest - 1, cost });
	}

	cin >> start >> dest;
	start--;
	dest--;
	visited[start] = true; //시작 도시부터 다익스트라 돌려야되니까 visit true로 바꿔주고
	now = start;
	dist[start] = 0; //출발도시로부터 출발도시까지의 거리는 0으로 초기화
	
	while (now != -1) { //더이상 탐색할 도시가 없으면 종료
		dijkstra(now);//현재 도시를 경유지로 하여 dist 배열 갱신
		now = newStart(n); //다음으로 탐색할 도시 설정
	}
	cout << dist[dest];//start로부터 dest까지의 최소비용 출력
}
