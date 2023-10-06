#include <iostream>
#include <vector>

using namespace std;
using lld = long long;

int n, m;
int map[500][500];
int stop[500][500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int cnt;

void dfs(int x,int y) {
	if (stop[x][y]>= 0)return;
	stop[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
		if (map[xx][yy] < map[x][y]) {
			dfs(xx, yy);
			stop[x][y] += stop[xx][yy];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			stop[i][j] = -1;
			cin >> map[i][j];
		}
	}
	stop[n - 1][m - 1] = 1;
	dfs(0,0);

	cout << stop[0][0];

	return 0;
}
