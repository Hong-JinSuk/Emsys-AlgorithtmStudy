#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, temp, sum;

	cin >> n >> k;

	vector<int> coin(n, 0);
	vector<int> dp(k+1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin.begin(), coin.end());

	for (int i = 0; i < n; i++) {
		temp = coin[i];

		//cout << "coin : " << coin[i] << "\n";

		for (int j = k; j >=temp; j--) {
			sum = 0;
			for (int p = 0; p * temp <= j; p++){
				sum += dp[j-p*temp];
			}
			dp[j] = sum;

			//cout << "dp[" << j << "] is : " << dp[j] << " ";
		}

		//cout << "\n";
	}

	cout << dp[k];
}
