#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;

struct bag {
	int val;
	int wei;
};

bag obj[100];
int dp[100][100001]; // dp[][weight] = value

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> obj[i].wei >> obj[i].val;
	}
	
	// 모든 가능성의 수를 탐색함. 100x100000 이라 2초안에 가능함
	for (int i = 1; i <= n; i++) {
		int weight = obj[i].wei;
		for (int j = 1; j <= k; j++) {
			if (j - weight < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], obj[i].val + dp[i - 1][j - weight]);
		}
	}
	
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	
	cout << dp[n][k];

	return 0;
}
