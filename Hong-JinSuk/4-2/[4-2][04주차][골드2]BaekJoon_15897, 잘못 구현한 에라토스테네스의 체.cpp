#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	long long cnt = 0;
	cin >> n;

	for (int Div = 1; Div < n;) {
		int Mod = (n - 1) % Div; // 나머지
		int ans = (n - 1) / Div; // 몫
		int mul = Mod / ans + 1;
		cout << "mul : " << mul << ", Div : " << Div << endl;
		cout << mul * (ans + 1) << endl;
		cnt += mul * (ans + 1);
		Div += mul;
	}
	
	cout << cnt + 1;

	return 0;
}

//12를 넣어본 진행도
//1 : 11 / 0
//2 : 5 / 1
//3 : 3 / 2
//4 : 2 / 3
//5 : 2 / 1
//6 : 1 / 5
//7 : 1 / 4
//8 : 1 / 3
//9 : 1 / 2
//10 : 1 / 1
//11 : 1 / 0
//12 : 0 / 11