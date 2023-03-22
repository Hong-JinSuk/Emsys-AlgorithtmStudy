#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, Start, End;

vector<pair<int,int>> Lec;
priority_queue<int, vector<int>, greater<int>> q; // �������� queue

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> Start >> End;
		Lec.push_back({ Start,End }); // ���� ���� ���� ���Ϳ� �־���
	}
	sort(Lec.begin(), Lec.end()); // ������������ �ٲ���
	q.push(Lec[0].second); // ������ �־���
}

void Solve() {
	for (int i = 1; i < n; i++) {

		// �����ϴ� �ð���(ex 3) ������ �ð����� ������(ex 8) ť�� �־��ش�.
		if (Lec[i].first < q.top()) q.push(Lec[i].second);
		// �׷��� ������ ex(start=6, end=6)
		else {
			q.push(Lec[i].second); // �����ϴ� �ð��� �־��ְ�
			q.pop(); // ������ �ð��� ����.
		} // �� �Ʒ� ������ ��� 5->6, 6->11 ���� ť�� top�� �ִ� 6�� pop, 11�� push ����.
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