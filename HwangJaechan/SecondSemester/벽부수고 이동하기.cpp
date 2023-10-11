#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX 1000000001
#define INF 100000000001

using namespace std;
using lld = long long;

typedef struct inf {
	int x, y;
	bool iswall;
};

int n, m;
vector<string>loads;
int cnt[1000][1000];
bool passwall[1000][1000];

int sol() {
	if (n == 1 && m == 1)return 1;
	int c = 1;
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	queue<inf>q;
	q.push({ 0,0,0 });
	cnt[0][0] = 1;
	while (!q.empty()) {
		c++;
		queue<inf>tmp;
		while (!q.empty()) {
			int nx = q.front().x;
			int ny = q.front().y;
			bool iswall = q.front().iswall;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = nx + dx[i];
				int y = ny + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m)continue;
				if (cnt[x][y] && iswall)continue;
				if (iswall && loads[x][y] == '1')continue;
				if (cnt[x][y]) {
					if (!passwall[x][y])
						continue;
					else if (passwall[x][y] && iswall)
						continue;
				}
				if (x == n - 1 && y == m - 1)return c;
				inf k = { x,y,loads[x][y] - '0'+iswall };
				passwall[x][y] = k.iswall;
				cnt[x][y] = c;
				tmp.push(k);
			}
		}
		swap(tmp, q);
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	loads.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> loads[i];
	}

	cout << sol();

	return 0;
}
