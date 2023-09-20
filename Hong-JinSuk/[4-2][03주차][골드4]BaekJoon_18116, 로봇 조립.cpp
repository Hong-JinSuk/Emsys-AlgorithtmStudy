#include<iostream>
#include<vector>
#define endl "\n"
#define MAX 1000001
using namespace std;

// ���� �ð��ʰ��� �ڵ�(����ȭ X, ������ ���)
//struct in_out
//{
//	vector<int> in;
//	vector<int> out;
//};
//
//int n, a, b, Find;
//in_out Robot[MAX];
//bool isvisit[MAX];
//
//void Search(int cur, int& answer) {
//	isvisit[cur] = true;
//	answer++;
//	for (auto Post : Robot[cur].in) { // ���� ������ ���
//		if(!isvisit[Post])
//			Search(Post, answer);
//	}
//	for (auto Next : Robot[cur].out) { // ���� ������ ���
//		if(!isvisit[Next])
//			Search(Next, answer);
//	}
//	isvisit[cur] = true;
//	return;
//}
//
//void input() {
//	cin >> n;
//	char key;
//	for (int i = 0; i < n; i++) {
//		cin >> key;
//		if (key == 'I') {
//			cin >> a >> b; // b�� a�� ����
//			Robot[a].in.push_back(b); // a <- b
//			Robot[b].out.push_back(a); // b -> a
//		}
//		else if (key == 'Q') {
//			cin >> Find;
//			int answer = 0;
//			Search(Find, answer);
//			cout << answer << endl;
//		}
//	}
//}

int n, a, b, now;
int Parent[MAX];
int Sum[MAX];

int Find_Parent(int cur) {
	if (Parent[cur] == cur) return cur; // ������ ������ ��
	return Parent[cur] = Find_Parent(Parent[cur]); // �װ� �ƴϸ� ������ ����
}

void union_set(int A, int B) {
	int A_parent = Find_Parent(A);
	int B_parent = Find_Parent(B);

	// �̹� �����̸�
	if (A_parent == B_parent) return;
	else {
		// �� �������� �θ�� ����
		int Min = min(A_parent, B_parent);
		int Max = max(A_parent, B_parent); 
		Parent[Max] = Min; // �ʵ� �ڽ��� �Ƕ�
		Sum[Min] += Sum[Max];
		Sum[Max] = 0;
	}
	return;
}

void input() {
	cin >> n;
	char key;
	for (int i = 0; i < n; i++) {
		cin >> key;
		if (key == 'I') {
			cin >> a >> b;
			union_set(a, b);
		}
		else if (key == 'Q') {
			cin >> now;
			int answer = Find_Parent(now); // �θ� ã��
			cout << Sum[answer] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	for (int i = 1; i < MAX; i++) {
		Parent[i] = i; // �ڱ��ڽ�
		Sum[i] = 1; // �⺻���� ��ǰ�� 1���ʿ�
	}

	input();

	return 0;
}