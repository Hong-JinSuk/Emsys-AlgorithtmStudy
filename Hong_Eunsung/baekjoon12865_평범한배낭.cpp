#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, w, v, temp1, temp2;
	cin >> n >> k;
	vector<int> dp(k+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		for (int j = k; j >= 0; j--) {
			if (j - w < 0)
				break;
			temp1 = dp[j];
			temp2 = dp[j - w] + v;
			dp[j] = temp1 >= temp2 ? temp1 : temp2;
		}
	}
	cout << dp[k];
}