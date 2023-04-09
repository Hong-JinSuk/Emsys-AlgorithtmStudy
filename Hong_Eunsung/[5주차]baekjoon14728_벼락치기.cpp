#include<iostream>
#include<vector>(
using namespace std;

int dp[10001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, tempT, tempS, max = 0;
	cin >> n >> t;
	vector<int> times(n);
	vector<int> scores(n);

	for (int i = 0; i < n; i++)
		cin >> times[i] >> scores[i];

	for (int i = 0; i < n; i++) {
		tempT = times[i];
		tempS = scores[i];
		for (int j = t; j >= tempT; j--) {
			dp[j] = dp[j - tempT] + tempS > dp[j] ? dp[j - tempT] + tempS : dp[j];
			if (dp[j] > max)
				max = dp[j];
		}
	}


	cout << max;
}
