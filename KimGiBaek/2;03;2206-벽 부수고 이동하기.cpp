#include <iostream>
#include <queue>

using namespace std;

typedef struct POS {
	int x;
	int y;
	bool broken = false;
};

int sero, garo, map[1001][1001], vis[1001][1001];
queue<POS> nextsearch;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> sero >> garo;
	for (int i = 0; i < sero; i++) {
		for (int j = 0; j < garo; j++) {
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}
	POS start;
	start.x = start.y = 0;
	nextsearch.push(start);

	int range = 1;
	for (; "SOLVE"; range++) {
		if (nextsearch.empty()) {
			cout << "-1";
			return 0;
		}
		int loopcount = nextsearch.size();
		while (loopcount--) {
			POS nowpos = nextsearch.front();
			int x = nowpos.x, y = nowpos.y;
			nextsearch.pop();
			if (vis[y][x] == 2 || (vis[y][x] == 1 && nowpos.broken))
				continue;
			vis[y][x] = !nowpos.broken + 1;
			if (x == garo - 1 && y == sero - 1) {
				cout << range;
				return 0;
			}
			if (x > 0 && vis[y][x - 1] != 2 && !(vis[y][x - 1] == 1 && nowpos.broken)) {
				if (map[y][x - 1] == 1 && !nowpos.broken) {
					POS nextpos;
					nextpos.x = x - 1;
					nextpos.y = y;
					nextpos.broken = true;
					nextsearch.push(nextpos);
				}
				else if (map[y][x - 1] == 0) {
					POS nextpos;
					nextpos.x = x - 1;
					nextpos.y = y;
					nextpos.broken = nowpos.broken;
					nextsearch.push(nextpos);
				}
			}
			if (y > 0 && vis[y - 1][x] != 2 && !(vis[y - 1][x] == 1 && nowpos.broken)) {
				if (map[y - 1][x] == 1 && !nowpos.broken) {
					POS nextpos;
					nextpos.x = x;
					nextpos.y = y - 1;
					nextpos.broken = true;
					nextsearch.push(nextpos);
				}
				else if (map[y - 1][x] == 0) {
					POS nextpos;
					nextpos.x = x;
					nextpos.y = y - 1;
					nextpos.broken = nowpos.broken;
					nextsearch.push(nextpos);
				}
			}
			if (x < garo - 1 && vis[y][x + 1] != 2 && !(vis[y][x + 1] == 1 && nowpos.broken)) {
				if (map[y][x + 1] == 1 && !nowpos.broken) {
					POS nextpos;
					nextpos.x = x + 1;
					nextpos.y = y;
					nextpos.broken = true;
					nextsearch.push(nextpos);
				}
				else if (map[y][x + 1] == 0) {
					POS nextpos;
					nextpos.x = x + 1;
					nextpos.y = y;
					nextpos.broken = nowpos.broken;
					nextsearch.push(nextpos);
				}
			}
			if (y < sero - 1 && vis[y + 1][x] != 2 && !(vis[y + 1][x] == 1 && nowpos.broken)) {
				if (map[y + 1][x] == 1 && !nowpos.broken) {
					POS nextpos;
					nextpos.x = x;
					nextpos.y = y + 1;
					nextpos.broken = true;
					nextsearch.push(nextpos);
				}
				else if (map[y + 1][x] == 0) {
					POS nextpos;
					nextpos.x = x;
					nextpos.y = y + 1;
					nextpos.broken = nowpos.broken;
					nextsearch.push(nextpos);
				}
			}

		}
	}
}
