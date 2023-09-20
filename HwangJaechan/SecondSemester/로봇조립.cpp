#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001

using namespace std;

int n;
vector<int>robots(MAX);
vector<int>parts(MAX);

int Find(int a) {
	if (a == robots[a])return a;
	else {
		robots[a] = Find(robots[a]);
		return robots[a];
	}
}

void Union(int a,int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb)return;
	else {
		parts[pa] += parts[pb];
		robots[pb] = pa;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	char a;int b, c;
	cin >> n;
	for (int i = 0; i < MAX; i++)robots[i] = i,parts[i] = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 'I') {
			cin >> b >> c;
			Union(b, c);
		}
		else {
			cin >> b;
			cout << parts[Find(b)] << '\n';
		}
	}

	return 0;
}
