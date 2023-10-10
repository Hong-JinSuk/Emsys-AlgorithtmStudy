#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
long long dp[57];
int A, B;
// dp[n]=dp[n-1]*2 + 2^(n-1), dp[0]=1 // n+1 = 1의 갯수 ex) n=3 => 111
// ex) 1111 => (111)*2 + 2^3

void getdp() {
	dp[0] = 1;
	for (int i = 1; i < 57; i++) {
		dp[i] = dp[i - 1] * 2 + pow(2, i);
		//cout << dp[i] << endl;
	}
}

int solution(long long bit) {
	long long answer = 0;
	long long temp = bit;
	vector<int> bits;

	while (bit != 0) {
		bits.push_back(bit % 2);
		bit /= 2;
	}
	for (int i = bits.size() - 1; i > -1; i--) {
		if (bits[i] == 1) {
			// temp : (1)[1]11 ->(1)을 제거시 [1] 위치가 temp만큼 들어감
			answer += dp[i - 1] + 1 + temp - (long long)pow(2, i); 
			temp -= (long long)pow(2, i); // (1) 제거
		}
	}
	
	return answer;
}

int main() {

	cin >> A >> B;
	getdp();
	cout << solution(B) - solution(A - 1);

	return 0;
}