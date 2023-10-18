#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX 1000000001
#define INF 100000000001

using namespace std;
using lld = long long;

int n, m, k;
vector<int>candy;
vector<int>parent;
vector<int>weight;
vector<int>dp;
int Find(int a) {
	if (a == parent[a])return a;
	else {
		parent[a] = Find(parent[a]);
		return parent[a];
	}
}

void Union(int a,int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa== pb) {
		return;
	}
	else {
		parent[pb] = pa;
		candy[pa] += candy[pb];
		weight[pa] += weight[pb];
	}
}

void knapsack() {
	for (int i = 1; i <= n; i++) {
		if (parent[i] != i) continue;
		for (int j = dp.size()-1; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + candy[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> n >> m >> k;
	candy.resize(n+1);
	parent.resize(n+1);
	weight.resize(n+1);
	dp.resize(min(k+1,3000+1));
	for (int i = 1; i <= n; i++) {
		cin >> candy[i];
		parent[i] = i;
		weight[i] = 1;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	knapsack();

	cout << dp[k-1];

	return 0;
}
