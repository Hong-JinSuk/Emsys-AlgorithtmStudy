#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using rinfo = tuple<int, int, int>;//x,y,direct; 
using oper = tuple<int, char, int>;

int A,B;
int map[101][101];
vector<rinfo>robots(101);
queue<oper>op;

int direct(char a) {
	if (a == 'N')return 0;
	else if (a == 'E')return 1;
	else if (a == 'S')return 2;
	else return 3;
}
void tright(int rn,int l) {
	int d = get<2>(robots[rn]);
	d = (d + l) % 4;
	get<2>(robots[rn]) = d;
}
void tleft(int rn,int l) {
	int d = get<2>(robots[rn]);
	d = (d + l*3) % 4;
	get<2>(robots[rn]) = d;
}
void gof(int rn, int c) {
	int x = get<0>(robots[rn]);
	int y = get<1>(robots[rn]);
	int d = get<2>(robots[rn]);
	int dx, dy;
	if (d == 0)dx = 1, dy = 0;
	else if (d == 1) dx = 0, dy = 1;
	else if (d == 2) dx = -1, dy = 0;
	else dx = 0, dy = -1;
	map[x][y] = 0;
	for (int i = 0; i < c; i++) {
		x += dx, y += dy;
		if (x <= 0 || x > B || y <= 0 || y > A) {
			cout << "Robot " << rn << " crashes into the wall";
			exit(0);
		}
		else if (map[x][y]) {
			cout << "Robot " << rn << " crashes into robot " << map[x][y];
			exit(0);
		}
	}
	map[x][y] = rn;
	get<0>(robots[rn]) = x;
	get<1>(robots[rn]) = y;
}

void sol() {
	while (!op.empty()){
		int rn = get<0>(op.front());
		int lop = get<2>(op.front());
		char order = get<1>(op.front());
		op.pop();
		if (order == 'R') {
			tright(rn, lop);
		}
		else if (order == 'L') {
			tleft(rn, lop);
		}
		else {
			gof(rn, lop);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int  n, m;
	cin >> A >> B >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a, b;
		char c;
		cin >> b >> a >> c;
		map[a][b] = i;
		robots[i]=(make_tuple(a, b, direct(c)));
	}
	for (int i = 0; i < m; i++) {
		int a, c;
		char b;
		cin >> a >> b >> c;
		op.push(make_tuple(a, b, c));
	}
	sol();
	cout << "OK";
	return 0;
}
