// 79% ���� �ȳѾ
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX 100002
#define endl "\n"
using namespace std;

int n, q;
long long Box[MAX]; // ���簢���� ��ĥ�� �迭
int Next[MAX]; // ����ĭ���� �̵��� ����ĭ ����
int cnt = 0;
void Painting(int start, int end, int x) {
	int next = Next[end + 1];
	int post = start - 1;
	// 1~1, 2~2, 3~3, 4~4, ... , 100000~100000 �� ����
	//while (1) { // ������ �ڽ������� next�� �̵��� �� �ְ� ��ŷ��
	//	if (Next[post] == post || Next[post] == next) {
	//		break;
	//	}
	//	Next[post] = next;
	//	post--;
	//}
	// 5000�� / 10^5
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
	// ������ �Ⱦ��ڴ� 1~1, 2~2, 3~3 ... 50000~50000 �ϰ� 1~50000 �ݺ��� ����
	while (start <= end) {
		if (Box[start] == 0) { // ������ĥ���� ���� ĭ�̸�
			Box[start] = x; // ��ĥ
			Next[start] = next; // ��ŷ
			start++; // ���� ĭ����
		}
		else { // �̹� ��ĥ�� ĭ�̸�
			start = Next[start]; // ���� ĭ���� �̵�
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
		Next[i] = i; // �ڱ� �ڽ��� ĥ�ؾ���
	
	input();

	for (int i = 1; i <= n; i++)
		cout << Box[i] << " ";
	cout << endl;

	for (int i = 1; i <= n; i++)
		cout << Next[i] << " ";

	return 0;
}