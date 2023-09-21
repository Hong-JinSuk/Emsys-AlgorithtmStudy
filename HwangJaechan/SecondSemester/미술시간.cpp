#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define MAX 3000000000

using namespace std;
using lld = long long;

int color[100001];
int goTo[100001];

void paint(int a, int b, int c) {
	vector<int>tmp;
	int e = b;
	for (int i = a; i <= b; i++) {
		if (color[i]) { // 색이 이미 칠해져있는 경우 
			int t = i;
			tmp.push_back(t);
			while (t != goTo[t]) { // 색이 칠해져있는 마지막까지 이동 
				tmp.push_back(t);
				t = goTo[t];
			}
			e = max(t, e); // 가장 마지막 색이 칠해져있는 곳 저장
			i = t; // cursor이동 
		}
		else { // 색이 칠해져있지 않은 경우 
			color[i] = c;// 색칠함
			tmp.push_back(i);
		}
	}
	for (auto i : tmp) {//중간에 들른곳을 모두 마지막 e로 업데이트 
		goTo[i] = e;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) goTo[i] = i;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		paint(a, b, c);
	}

	for (int i = 1; i <= n; i++) cout << color[i] << ' ';
	
	return 0;
}
