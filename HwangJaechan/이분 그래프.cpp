#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define MAX 1000001

using namespace std;
using lld = long long;
using info = pair<pair<int,int>, int>;
using dvect = vector<vector<int>>;

dvect link;
vector<int>color;

bool bfs(int s) {
	if (color[s])return 0;
	queue<int>q;
	q.push(s);
	color[s] = 1;
	while (!q.empty()) {
		queue<int>tmp;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (auto i : link[f]) {
				if (color[i]) {
					if (color[i] == color[f]) {
						return 1;
					}
				}
				else {
					tmp.push(i);
					if (color[f] == 1)
						color[i] = 2;
					else color[i] = 1;
				}
			}
		}
		swap(q, tmp);
	}
	return 0;
}

void sol() {
	int v, e;
	cin >> v >> e;
	link.clear(), color.clear();
	link.resize(v+1), color.resize(v+1);

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		cnt +=bfs(i);
	}
	if (cnt)
		cout << "NO\n";
	else
		cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	while (n--)sol();

	return 0;
}
