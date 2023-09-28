#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int k, V, E, u, v;
bool isBi = true;
int isvisit[20001]; // 1, -1
vector<int> edge[20001];

// 그냥 싸이클이 있으면 안되는줄 알았음... 
//void dfs(int post, int start) {
//	isvisit[start] = true;
//	for (int i = 0; i < edge[start].size(); i++) {
//		int next = edge[start][i];
//		if (isvisit[next] && post != next) {
//			isBi = false;
//			return;
//		}
//		if (isvisit[next]) continue;
//		dfs(start, next);
//	}
//	return;
//}

bool BFS(int start) {
	queue<int> q;
	q.push(start);
	isvisit[start] = 1;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur = q.front(); q.pop();
			for (int j = 0; j < edge[cur].size(); j++) {
				int next = edge[cur][j];
				// 이웃하면 false
				if (isvisit[next] == isvisit[cur]) return false;
				// 아직 간적이 없으면
				if (isvisit[next] == 0) {
					isvisit[next] = isvisit[cur] * -1;
					q.push(next);
				}
			}
		}
	}
	return true;
}

void input() {

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> V >> E;

		for (int j = 0; j < E; j++) {
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		for (int j = 1; j <= V; j++) {
			if (isvisit[j] == 0) {
				if (!BFS(j)) {
					cout << "NO\n";
					break;
				}
			}
			if (j == V)cout << "YES\n";
		}
		
		for (int j = 1; j < V + 1; j++)
			edge[j].clear();
		for (int j = 1; j < V + 1; j++)
			isvisit[j] = false;
	}
	return;
}

int main() {

	input();

	return 0;
}