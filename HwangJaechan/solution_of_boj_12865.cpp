#include <iostream>

using namespace std;
using things = pair<int, int>;

things item[100];
int dp[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> item[i].first >> item[i].second;
	for (int i = 0; i < n; i++) {
		int w = item[i].first;
		int val = item[i].second;
		for (int j = m; j >=w; j--) {
			dp[j] = max(dp[j], dp[j - w] + val);
		}
	}

	cout << dp[m];

	return 0;
}
