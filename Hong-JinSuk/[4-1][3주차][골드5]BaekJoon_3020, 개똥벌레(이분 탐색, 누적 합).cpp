#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

int n, h, Top, Down;
int DownToTop[500001];
int TopToDown[500001];
int Answer[500001];

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> h;

	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			cin >> Down;
			DownToTop[Down]++;
		}
		else {
			cin >> Top;
			TopToDown[h - Top + 1]++;
		}
	}

	for (int i = h; i >= 2; i--) {
		DownToTop[i - 1] += DownToTop[i];
	}

	for (int i = 1; i <= h; i++) {
		TopToDown[i + 1] += TopToDown[i];
	}

	for (int i = 1; i <= h; i++) {
		Answer[i] = DownToTop[i] + TopToDown[i];
	}

	/*for (int i = 1; i <= h; i++) {
		cout << "answer : " << Answer[i] << endl;
	}*/

	int answer = 9999999;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		if (Answer[i] < answer) {
			answer = Answer[i];
			cnt = 1;
		}
		else if (answer == Answer[i]) cnt++;
	}
	cout << answer << " " << cnt;

	return 0;
}