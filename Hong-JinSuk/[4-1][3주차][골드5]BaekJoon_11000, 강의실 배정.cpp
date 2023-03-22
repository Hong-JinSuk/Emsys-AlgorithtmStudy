#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, Start, End;

vector<pair<int,int>> Lec;
priority_queue<int, vector<int>, greater<int>> q; // 오름차순 queue

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> Start >> End;
		Lec.push_back({ Start,End }); // 시작 도착 지점 벡터에 넣어줌
	}
	sort(Lec.begin(), Lec.end()); // 오름차순으로 바꿔줌
	q.push(Lec[0].second); // 시작점 넣어줌
}

void Solve() {
	for (int i = 1; i < n; i++) {

		// 시작하는 시간이(ex 3) 끝나는 시간보다 빠르면(ex 8) 큐에 넣어준다.
		if (Lec[i].first < q.top()) q.push(Lec[i].second);
		// 그렇지 않으면 ex(start=6, end=6)
		else {
			q.push(Lec[i].second); // 시작하는 시간을 넣어주고
			q.pop(); // 끝나는 시간을 뺀다.
		} // 맨 아래 예제의 경우 5->6, 6->11 에서 큐의 top에 있는 6을 pop, 11을 push 해줌.
	}
}

int main() {

	Input();
	Solve();
	cout << q.size();

	return 0;
}

//8
//1 8
//9 16
//3 7
//8 10
//10 14
//5 6
//6 11
//11 12