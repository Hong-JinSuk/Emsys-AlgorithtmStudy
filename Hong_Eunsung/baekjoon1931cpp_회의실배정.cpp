#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meetTime {
	int start;
	int end;
};

bool compare(meetTime a, meetTime b) {
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp, max = 0, latest = 0;
	cin >> n;
	vector<meetTime> meet(n);
	for (int i = 0; i < n; i++) {
		cin >> meet[i].start >> meet[i].end;
	}

	sort(meet.begin(), meet.end(), compare);
	latest = meet.back().end;
	vector<int>dp(latest+1, 0);


	//dp[0]만 따로 설정
	dp[0] = 0;
	temp = 0;
	while (meet[temp].end == 0) {
		dp[0]++;
		temp++;
	}

	int j = 1; //dp 번호
	for (int i = temp; i < n; i++) { //i에 따라 meet를 앞에서부터 탐색
		//test code
		cout << "i : " << i << "\n";

		while (j < meet[i].end) {//다음으로 검사할 meet의 종료시간이 현재 dp번호보다 크다면
			dp[j+1] = dp[j];
			j++;
		}

		temp = dp[meet[i].start] + 1;
		dp[j] = dp[j-1] < temp ? temp : dp[j-1];
		max = dp[j] > max ? dp[j] : max;

	}
	cout << max;
}
