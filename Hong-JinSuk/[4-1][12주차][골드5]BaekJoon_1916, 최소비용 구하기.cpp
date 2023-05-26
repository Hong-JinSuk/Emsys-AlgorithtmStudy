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
	
	visited[start] = 0; // ���۳���� ����� 0��.

	priority_queue<pair<int,int>> q; // ����� ���� ������ ����
	q.push({ start, visited[start] }); // ���� ���, ���۳��
	

	while (!q.empty()) {
		int cur = q.top().first; // cur = ���۳��
		q.pop(); // ��� �޾ƿ��� ����.

		for (int i = 0; i < Bus[cur].size(); i++) { // ���� ��ġ���� ������ �� �ִ� ������ Ž��
			int next = Bus[cur][i].second;
			int next_cost = Bus[cur][i].first;
			if (visited[cur] + next_cost < visited[next]) { // Ž���� ��ΰ� �� ����� ��ζ�� ������Ʈ ���ش�.
				visited[next] = visited[cur] + next_cost; // ���� ���� ��� ������Ʈ
				q.push( { next, visited[next] }); // �������� �߰�
				//cout << "push : " << next << endl;
			}
		}
	}

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> Start >> End >> cost;
		Bus[Start].push_back({ cost, End }); // Bus[��߳��].push_back({��������, ���})
	}
	
	cin >> Start >> End; // ���������� a->b�� �̵��Ҷ� ��� �ּҺ���� ���ؾ���.

	for (int i = 1; i <= n; i++) { // Ž���� ��, ����� ���� ������ Ž���� ���� ���ش�.
		if (Bus[i].size() > 0) sort(Bus[i].begin(), Bus[i].end());
	}

	for (int i = 1; i < 1001; i++) {
		visited[i] = INF; // �湮���� �ʱ�ȭ 
	}
	
	Serach(Start);
	cout << visited[End];

	return 0;
}