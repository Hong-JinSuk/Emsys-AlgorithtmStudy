#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int N, Min = 2000000001;
vector<int> Water;

void input() {
	cin >> N;
	int Li;
	while (N--) {
		cin >> Li;
		Water.push_back(Li);
	}
	sort(Water.begin(), Water.end()); // -9999 ~ 0 ~ 9999
}

int main() {
	
	input();
	int left = 0, right = Water.size() - 1;
	int Sum, left_ans, right_ans;

	while (left < right) { // ��������
		Sum = Water[left] + Water[right];
		if (Sum == 0) { // 0�� �ּ��� ��
			left_ans = left;
			right_ans = right;
			break;
		}
		if (Min > abs(Sum)) { // ���� �ּҰ� => update
			Min = abs(Sum);
			left_ans = left;
			right_ans = right;
		}
		if (Sum > 0) right--; // ����� ���� �ٿ�����?
		else left++; // ������ ���� �÷�����?
	}
	cout << Water[left_ans] << " " << Water[right_ans];

	return 0;
}