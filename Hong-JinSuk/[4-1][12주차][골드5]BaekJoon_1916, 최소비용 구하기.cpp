#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
#define INF 987654321
using namespace std;

int n, m, Start, End, cost;
int visited[1001];
vector<pair<int,int>> Bus[100001];

void Serach(int start) {
	
	visited[start] = 0; // 시작노드의 비용은 0임.

	priority_queue<pair<int,int>> q; // 비용이 낮은 순서로 진행
	q.push({ start, visited[start] }); // 현재 비용, 시작노드
	

	while (!q.empty()) {
		int cur = q.top().first; // cur = 시작노드
		q.pop(); // 노드 받아오고 빼줌.

		for (int i = 0; i < Bus[cur].size(); i++) { // 현재 위치에서 움직일 수 있는 모든방향 탐색
			int next = Bus[cur][i].second;
			int next_cost = Bus[cur][i].first;
			if (visited[cur] + next_cost < visited[next]) { // 탐색한 경로가 더 가까운 경로라면 업데이트 해준다.
				visited[next] = visited[cur] + next_cost; // 다음 지점 비용 업데이트
				q.push( { next, visited[next] }); // 다음지점 추가
				//cout << "push : " << next << endl;
			}
		}
	}

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> Start >> End >> cost;
		Bus[Start].push_back({ cost, End }); // Bus[출발노드].push_back({도착지점, 비용})
	}
	
	cin >> Start >> End; // 최종적으로 a->b로 이동할때 드는 최소비용을 구해야함.

	for (int i = 1; i <= n; i++) { // 탐색할 때, 비용이 낮은 순서로 탐색을 가게 해준다.
		if (Bus[i].size() > 0) sort(Bus[i].begin(), Bus[i].end());
	}

	for (int i = 1; i < 1001; i++) {
		visited[i] = INF; // 방문여부 초기화 
	}
	
	Serach(Start);
	cout << visited[End];

	return 0;
}