#include <iostream>
#include <map>

using namespace std;

map<int, int>scount; // 시작하는 시각에 대한 정보
map<int, int>ecount; // 끝나는 시각에 대한 정보

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; // 입력 받는 부분
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		scount[a]++;
		ecount[b]++;
	}

	auto i = scount.begin(); // 투포인터로 해결 
	auto j = ecount.begin();

	int r = 0; // 필요한 강의실의 수 
	int maxi = 0;
	while (i != scount.end()) {
		if (i->first >= j->first || i==scount.end()) { // 끝나는 시각이 시작하는 시각보다 같거나 앞서는 경우 현재 강의실을 비울 수 있음
			r -= j++->second;
		}
		else { // 강의가 끝나지 않았음에도 강의실이 필요하므로 필요한 강의실 증가
			r += i++->second; 
		}
		maxi = max(r, maxi); // 필요한 강의실의 최대목록 갱신
	}

	cout << maxi;
	return 0;
}
