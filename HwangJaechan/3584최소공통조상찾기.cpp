#include <iostream>
#include <set>
#include <vector>

using namespace std;

int parent[10001];
int visit[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	for (int j = 0; j < t; j++) {

		int n, a, b;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			parent[i] = i; visit[i] = 0;
		}
		
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			parent[b] = a;
		}
		
		cin >> a >> b;
		visit[a] = 1;
		while (a != parent[a]) {
			a = parent[a];
			visit[a] = 1;
		}
		while (1) {
			if (visit[b]) {
				cout << b << '\n';
				break;
			}
			b = parent[b];
		}
	}

	return 0;
}
