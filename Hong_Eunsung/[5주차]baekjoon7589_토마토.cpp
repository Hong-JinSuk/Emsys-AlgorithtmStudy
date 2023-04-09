#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct tomato {
	int y;
	int x;
	int h;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dayCount = 0, notRiped = 0, n = 100, m = 100, h = 100;
	cin >> m >> n >> h;

	vector<vector<vector<int>>> tomatoBox(n, vector<vector<int>>(m, vector<int>(h)));
	queue<tomato> bfsQ;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tomatoBox[i][j][k];
				if (!tomatoBox[i][j][k])
					notRiped++;
				else if (tomatoBox[i][j][k] == 1) {
					bfsQ.push({ i, j, k });
				}
			}
		}
	}

	int dy[6] = { 0, 0, -1, 1, 0, 0 };
	int dx[6] = { -1, 1, 0, 0 , 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };

	while (!bfsQ.empty() && notRiped > 0) {
		int temp = bfsQ.size();

		for (int i = 0; i < temp; i++) {
			for (int j = 0; j < 6; j++) {
				int ny = bfsQ.front().y + dy[j];
				int nx = bfsQ.front().x + dx[j];
				int nz = bfsQ.front().h + dz[j];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || nz < 0 || nz >= h)
					continue;

				if (!tomatoBox[ny][nx][nz]) {
					tomatoBox[ny][nx][nz] = 1;
					bfsQ.push({ ny, nx, nz });
					notRiped--;
				}

			}
			bfsQ.pop();
		}
		dayCount++;
	}

	if (notRiped > 0)
		cout << -1;

	else
		cout << dayCount;
}
