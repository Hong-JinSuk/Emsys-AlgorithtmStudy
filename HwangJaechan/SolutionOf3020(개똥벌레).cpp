#include <iostream>
#include <algorithm>

using namespace std;

int u[250001]; // 종유석
int d[250001]; // 석순
int wall[500001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, h;
	int mini = 500000, counting = 500000; // 최솟값과 그 개수를 구할 변수 
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0)	cin >> u[i / 2]; // 짝수에는 항상 종유석이 오고
		else cin >> d[i / 2 + 1]; // 홀수번째에는 항상 석순이 온다. 
	}
	
	sort(u, u + n / 2+1); // 종유석의 경우 항상 n/2개 
	if (n % 2 != 0) sort(d, d + n / 2 + 2); // 석순의 경우 짝수면 n/2개
	else sort(d, d + n / 2 + 1); // 홀수면 n/2+1개 
	
	int r = 0; // 정렬된 종유석을 큰 것부터 wall 배열에 깨야하는 벽을 카운팅 
	for (int i = n / 2; i >= 1; i--) {
		r ++;
		for (int j = u[i]-1; j >= u[i - 1]; j--) {
			wall[h - j] += r;
		}
	}
	
	r = 0; // 정렬된 석순또한 wall 배열에 깨야하는 벽으로 카운팅
	for (int i = n / 2; i >= 1; i--) {
		wall[d[i]] -= r;
		r ++;
		for (int j = d[i]; j >= d[i - 1]; j--) {
			wall[j] += r;
		}
	}
	
	for (int i = 1; i <= h; i++) { // wall 배열을 탐색하며 mini 와 counting의 값 결정 
		if (mini > wall[i]) {
			mini = wall[i];
			counting = 1;
		}
		else if (mini == wall[i]) counting++;
	}

	cout << mini << ' ' << counting << '\n';

	return 0;
}
