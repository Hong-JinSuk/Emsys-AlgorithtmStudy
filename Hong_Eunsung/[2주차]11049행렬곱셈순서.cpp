#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, temp1, temp2, min, end;
	long long temp, minNum;
	cin >> n;
	vector<int> p(n + 2);

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		cin >> temp1 >> temp2;
		p[i] = temp1;
		p[i + 1] = temp2;
	}


	for (int i = 1; i < n; i++) { //dp12, 23, 34, ..... dp13, 24, 35, .... dp1n까지
		for (int j = 1; j <= n - i; j++) {//i가 1일때는  dp[1][2]부터 dp[n-1][n]까지. i가 n-1일때는 dp[1][n]만. 저장은 dp[j][j+i]로
			temp = 0;
			minNum = LLONG_MAX;
			for (int k = 0; k < i; k++) {
				temp = dp[j][j + k] + dp[j + k + 1][j + i] + p[j] * p[j + k + 1] * p[j + i + 1];
				if (minNum > temp)
					minNum = temp;
			}
			dp[j][j + i] = minNum;

		}
	}

	cout << dp[1][n];
}
