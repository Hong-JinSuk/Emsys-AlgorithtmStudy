#include<iostream>
#include<algorithm>
#include<cstring>
#define endl "\n"

using namespace std;

int n, m, Case;
bool visited[501] = { false, }; // �湮�� ������� ����
bool Route[501][501] = { false, }; // ��
bool isTree = true;

void DFS(int present, int root) { // ������ �� ���� ���� ��� �޾ƿ�, ���ư��� �ȵǱ� ����
	if (visited[root]) return; // ����Ŭ�� ���ƿ°�� ���ư�����.
	for (int i = 1; i <= n; i++) {
		if (Route[root][i] && i!=present) { // ���� ��忡�� ������ ���� �ְ�, �ڷ� ���ư��� ���� �ƴ϶��
			if (visited[i]) isTree = false; // ������忡 �湮���� ������ ��ȯ ����
			visited[root] = true;
			DFS(root, i);
		}
	}
}

int main() {

	Case = 0;

	while (1) {

		Case++; // �׳� ���̽� ����
		int count_tree = 0; // Ʈ�� ����

		cin >> n >> m;
		if (n == 0 && m == 0) break; // 0,0 �Է¹����� ����

		for (int i = 0; i < m; i++) { // �� �Է�
			int start, end;
			cin >> start >> end;
			Route[start][end] = true;
			Route[end][start] = true;
		}

		for (int i = 1; i <= n; i++) { // 1~n�� ��忡�� ��� Ž���ϴ� ��츦 ���´�.
			if (!visited[i]) { // �湮���� �ʾҴٸ� Ž��
				DFS(0, i);
				if (isTree) count_tree++; // �湮�ؼ� Ʈ���� �ϸ� 1�� ������.
				isTree = true; // �ʱ�ȭ
			}
		}

		if (count_tree == 0) cout << "Case " << Case << ": No trees." << endl;
		else if (count_tree == 1) cout << "Case " << Case << ": There is one tree." << endl;
		else cout << "Case " << Case << ": A forest of " << count_tree << " trees." << endl;

		fill_n(visited, 501, false); // �迭 �ʱ�ȭ
		memset(Route, false, sizeof(Route)); // �迭 �ʱ�ȭ
	}

	return 0;
}