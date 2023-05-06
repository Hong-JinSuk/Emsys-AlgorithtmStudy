#include<iostream>
#include<algorithm>
#include<cstring>
#define endl "\n"

using namespace std;

int n, m, Case;
bool visited[501] = { false, }; // 방문한 노드인지 여부
bool Route[501][501] = { false, }; // 길
bool isTree = true;

void DFS(int present, int root) { // 이전에 온 노드와 현재 노드 받아옴, 돌아가면 안되기 때문
	if (visited[root]) return; // 싸이클로 돌아온경우 돌아간다잉.
	for (int i = 1; i <= n; i++) {
		if (Route[root][i] && i!=present) { // 현재 노드에서 움직일 길이 있고, 뒤로 돌아가는 길이 아니라면
			if (visited[i]) isTree = false; // 다음노드에 방문한적 있으면 순환 존재
			visited[root] = true;
			DFS(root, i);
		}
	}
}

int main() {

	Case = 0;

	while (1) {

		Case++; // 그냥 케이스 갯수
		int count_tree = 0; // 트리 갯수

		cin >> n >> m;
		if (n == 0 && m == 0) break; // 0,0 입력받으면 종료

		for (int i = 0; i < m; i++) { // 길 입력
			int start, end;
			cin >> start >> end;
			Route[start][end] = true;
			Route[end][start] = true;
		}

		for (int i = 1; i <= n; i++) { // 1~n번 노드에서 모두 탐색하는 경우를 갖는다.
			if (!visited[i]) { // 방문하지 않았다면 탐색
				DFS(0, i);
				if (isTree) count_tree++; // 방문해서 트리라 하면 1개 더해줌.
				isTree = true; // 초기화
			}
		}

		if (count_tree == 0) cout << "Case " << Case << ": No trees." << endl;
		else if (count_tree == 1) cout << "Case " << Case << ": There is one tree." << endl;
		else cout << "Case " << Case << ": A forest of " << count_tree << " trees." << endl;

		fill_n(visited, 501, false); // 배열 초기화
		memset(Route, false, sizeof(Route)); // 배열 초기화
	}

	return 0;
}