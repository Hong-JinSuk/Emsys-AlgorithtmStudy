#include<iostream>
#include<algorithm>

using namespace std;

string F, S;

int dp[4002][4002] = { 0, };
int MAX = 0;

int main() {

	cin >> F >> S;

	for (int i = 0; i < F.length(); i++) {
		for (int j = 0; j < S.length(); j++) {
			if (F[i] == S[j]) { // 문자열이 일치하면 
				dp[i + 1][j + 1] = dp[i][j] + 1; // 대각선에서 1더한 값을 받아온다.
			}
			MAX = max(MAX, dp[i + 1][j + 1]); // 받아온 값과 현재 값중 큰 값으로 바꿔준다.
		}
	}

	cout << MAX;

	return 0;
}