// 79% 에서 안넘어감
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX 100002
#define endl "\n"
using namespace std;

int n, q;
long long Box[MAX]; // 직사각형에 색칠할 배열
int Next[MAX]; // 현재칸에서 이동할 다음칸 저장
int cnt = 0;
void Painting(int start, int end, int x) {
	int next = Next[end + 1];
	int post = start - 1;
	// 1~1, 2~2, 3~3, 4~4, ... , 100000~100000 에 약함
	//while (1) { // 이전의 박스에서도 next로 이동할 수 있게 마킹함
	//	if (Next[post] == post || Next[post] == next) {
	//		break;
	//	}
	//	Next[post] = next;
	//	post--;
	//}
	// 5000만 / 10^5
	if (cnt == 500) {
		int temp = MAX;
		for (int i = n + 1; i > 0; i--) {
			if (Next[i] == i) {
				temp = i;
				continue;
			}
			Next[i] = temp;
		}
		cnt = 0;
	}
	// 위에껄 안쓰자니 1~1, 2~2, 3~3 ... 50000~50000 하고 1~50000 반복에 약함
	while (start <= end) {
		if (Box[start] == 0) { // 아직색칠하지 않은 칸이면
			Box[start] = x; // 색칠
			Next[start] = next; // 마킹
			start++; // 다음 칸으로
		}
		else { // 이미 색칠한 칸이면
			start = Next[start]; // 다음 칸으로 이동
		}
	}
}


void input() {
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		Painting(a, b, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	for (int i = 1; i < MAX; i++)
		Next[i] = i; // 자기 자신을 칠해야함
	
	input();

	for (int i = 1; i <= n; i++)
		cout << Box[i] << " ";
	cout << endl;

	for (int i = 1; i <= n; i++)
		cout << Next[i] << " ";

	return 0;
}