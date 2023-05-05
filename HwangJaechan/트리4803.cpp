#include <iostream>
#include <queue>

using namespace std;

int arr[501]; // 자기자신을 가리키는 배열을 담을 통


void set0(int a) {
	for (int i = 1; i <= a; i++) arr[i] = i; // 각자 자신을 가리키도록 배열 초기화
}

void Union(int a, int b) { // Union으로 집합 합쳐줌
	int tmp = b,tmp2 = a, p;
	queue<int>mtemp;
	mtemp.push(tmp);
	mtemp.push(tmp2);
	while (arr[tmp2] != tmp2 && arr[tmp2] != -1) {
		mtemp.push(tmp2);
		tmp2 = arr[tmp2];
	}
	p = arr[tmp2];
	while (arr[tmp] != tmp && arr[tmp] != -1) {
		tmp = arr[tmp];
	}
	if (tmp == tmp2 || arr[tmp] == -1) p = -1;
  // -1은 트리에 사이클이 발생함을 의미함 
	mtemp.push(tmp);
	mtemp.push(tmp2);
	while (!mtemp.empty()) {
		arr[mtemp.front()] = p;
		mtemp.pop();
	}
}

void sol(int n, int m, int t) {
	int c = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++) { 
    // 트리의 root는 유일하기 때문에 배열에서 자기자신을 가리키는 것은 root를 의미
    //-1을 가리키는 경우는 트리가 아니므로 패스 
		if (arr[i] == i)c++;
	}
	if (c == 0) cout << "Case "<< t << ": No trees.\n";
	else if (c == 1) cout << "Case " << t << ": There is one tree.\n";
	else cout << "Case " << t << ": A forest of " << c << " trees.\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a, b,t = 1;
	while (1) {
		cin >> a >> b;
		if (!a && !b) break;
		set0(a);
		sol(a, b,t++);
	}
	return 0;
}
