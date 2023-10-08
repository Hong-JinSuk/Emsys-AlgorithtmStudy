#include <iostream>

using namespace std;

int 세로, 가로, map[505][505], submap[505][505];
bool subgo[505][505]; //탐색한칸인지 확인용, 한번확인한데면 굳이한번더확인안하기

int 이동(int, int);

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> 세로 >> 가로;
	for (int i = 0; i < 세로; i++) {
		for (int j = 0; j < 가로; j++) {
			cin >> map[i][j];
		}
	}
	submap[0][0] = 1;
	subgo[0][0] = true;
	cout << 이동(가로 - 1, 세로 - 1) ;
	/*
	for (int i = 0; i < 세로; i++) {
		cout << "\n";
		for (int j = 0; j < 가로; j++) {
			cout << submap[i][j] << " ";
		}
	}
	*/
}

int 이동(int x, int y) {
	if (subgo[y][x]) return submap[y][x];

	if (x > 0)			  if (map[y][x] < map[y][x - 1])	submap[y][x] += 이동(x - 1, y);
	if (y > 0)			  if (map[y][x] < map[y - 1][x])	submap[y][x] += 이동(x, y - 1);
	if (x < 가로 - 1)	if (map[y][x] < map[y][x + 1])	submap[y][x] += 이동(x + 1, y);
	if (y < 세로 - 1)	if (map[y][x] < map[y + 1][x])	submap[y][x] += 이동(x, y + 1);
	subgo[y][x] = true;
	return submap[y][x];
}
