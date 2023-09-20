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
		if (color[i]) {
			int t = i;
			tmp.push_back(t);
			while (t != goTo[t]) {
				tmp.push_back(t);
				t = goTo[t];
			}
			e = max(t, e);
			i = t;
		}
		else {
			color[i] = c;
			tmp.push_back(i);
		}
	}
	for (auto i : tmp) {
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
