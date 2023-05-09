#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int visit[5000001];
set<int> dae;
set<int> gue;

void era() {
	visit[0] = 1;
	visit[1] = 1;
	for (int i = 2; i <= 5000000; i++) {
		if (!visit[i]) {
			for (int j = i + i; j <= 5000000; j += i)visit[j] = 1;
		}
	}
}

void check(int tmp, long long& me, long long& en,set<int>& mine,set<int>& enemy) {
	if (visit[tmp]==1) {
		if (enemy.size() >= 3) {
			auto k = enemy.rbegin();
			for (int i = 0; i < 2; i++) k++;
			en += *k;
		}
		else en += 1000;
	}
	else {
		if (visit[tmp] == -1) {
			if (mine.find(tmp) != mine.end()) { mine.erase(tmp); }
			me -= 1000;
		}
		else {
			visit[tmp]=-1;
			mine.insert(tmp);
		}
	}
}

void sol(int n) {
	int a, b;
	long long d = 0, g = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		check(a, d, g, dae, gue);
		check(b, g, d, gue, dae);
	}
	if (d > g) {
		cout << "소수의 신 갓대웅";
	}
	else if (g > d) {
		cout << "소수 마스터 갓규성";
	}
	else cout << "우열을 가릴 수 없음";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	era();
	int n;
	cin >> n;
	sol(n);

	return 0;
}
