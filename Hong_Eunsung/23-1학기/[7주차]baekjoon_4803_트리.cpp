#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<bool> visited;
vector<vector<bool>> graph;
bool istree = 0;
int n;

//문제 : 이미 사이클이 형성된 그래프에 추가로 연결되는 간선에 대한 예외처리가 안된다. - bfs도중 사이클을 확인해도 리턴하지 않고 계속 탐색하도록 수정.

void bfs(int i) { // i번 노드에서 시작하는 dfs. 사이클을 발견하면 istree = false로 만든다.
	istree = true;
	int qsize, front = 0;
	queue<int> bfsQ;
	bfsQ.push(i);
	while (!bfsQ.empty()) {
		qsize = bfsQ.size();
		for (int i = 0; i < qsize; i++) { //큐의 모든 노드들에 대해
			front = bfsQ.front();
			for (int j = 0; j < n; j++) {
				if (graph[front][j]) { //연결되어있으면
					if (visited[j]) { //방문한 적 있는 곳이면 사이클이므로 istree = false로 바꿔준다.
						istree = false;
					}
					else { //방문한 적 없으면 큐에 넣는다.
						bfsQ.push(j);
						graph[j][front] = false; //방향이 정해졌으니까 저쪽에서 이쪽으로 오는건 지우기
						visited[j] = true;
					}
				}
			}
			bfsQ.pop();
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int m, a, b, treecount = 0, testcase = 1;
	cin >> n >> m;

	while (n || m) {
		treecount = 0;
		graph = vector<vector<bool>>(n, vector<bool>(n, 0));//새 테스트케이스이므로 그래프 초기화. 연결리스트로 구현 안 한 이유는 귀찮아서
		visited = vector<bool>(500, 0); //visited도 초기화
		for (int i = 0; i < m; i++) {//그래프 입력
			cin >> a >> b;
			graph[a - 1][b - 1] = true;
			graph[b - 1][a - 1] = true;
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i]) { //방문 안 했으면 탐색. 탐색 중 visited인 노드로 다시 돌아가면 사이클이 있다는 뜻이니 tree = false로 표시한다.
				visited[i] = true;
				bfs(i);
				if (istree)
					treecount++;
			}
			else //빼도 되는 부분
				continue;
		}

		cout << "Case " << testcase++ << ": ";
		if (!treecount)
			cout << "No trees.\n";
		else if (treecount == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << treecount << " trees.\n";

		cin >> n >> m;
	}
}
