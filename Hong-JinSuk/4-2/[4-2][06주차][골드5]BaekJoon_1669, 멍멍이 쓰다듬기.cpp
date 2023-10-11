#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

long long X, Y;

void input() {
	cin >> X >> Y;
	return;
}

long long plus_() {
	long long temp = Y - X;
	long long answer = 0, cnt = 0, Plus = 1, flag = 0;
	while (cnt < temp) {
		answer++;
		cnt += Plus;
		flag++;
		if (flag == 2) {
			flag = 0;
			Plus++;
		}
	}
	return answer;
}

int main() {

	input();
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cout << plus_();
	return 0;
}

//1 : 1, 1  // 1 Á¦°ö
//1 1 : 2, 2
//1 2 1 : 4, 3 // 2Á¦°ö
//1 2 2 1 : 6, 4
//1 2 3 2 1 : 9, 5 // 3Á¦°ö
//1 2 3 3 2 1 : 12, 6
//1 2 3 4 3 2 1 : 16, 7 // 4Á¦°ö
//1 2 3 4 4 3 2 1 : 20, 8
//1 2 3 4 5 4 3 2 1 : 25, 9 // 5Á¦°ö -> ((9+1)/2)^2
//ÀÌ·±½ÄÀ¸·Îµµ °¡´É