#include <iostream>

using namespace std;
using item = pair<int, int>; // time, val;
// 각 과목을 저장할 데이터타입 정의 
int napsack[10001]; // 배낭알고리즘으로 해결
item items[100];


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; // 과목의 개수와 투자 가능한 최대 시간 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		items[i] = make_pair(a, b);
	} // 입력
	for (int i = 0; i < n; i++) {
		int t = items[i].first;
		int val = items[i].second;
		for (int j = m; j >= t; j--) {
			napsack[j] = max(napsack[j], napsack[j - t] + val);
		} // DP - NapSack Problem 으로 해결 
	}
	cout << napsack[m] << '\n';
	return 0;
}
