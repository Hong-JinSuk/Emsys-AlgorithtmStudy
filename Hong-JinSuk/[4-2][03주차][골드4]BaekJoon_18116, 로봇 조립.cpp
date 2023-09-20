#include<iostream>
#include<vector>
#define endl "\n"
#define MAX 1000001
using namespace std;

// 기존 시간초과한 코드(최적화 X, 로직은 비슷)
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
//	for (auto Post : Robot[cur].in) { // 나를 지목한 놈들
//		if(!isvisit[Post])
//			Search(Post, answer);
//	}
//	for (auto Next : Robot[cur].out) { // 내가 지목한 놈들
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
//			cin >> a >> b; // b가 a를 지목
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
	if (Parent[cur] == cur) return cur; // 끝가지 왔으면 끝
	return Parent[cur] = Find_Parent(Parent[cur]); // 그게 아니면 끝까지 ㄱㄱ
}

void union_set(int A, int B) {
	int A_parent = Find_Parent(A);
	int B_parent = Find_Parent(B);

	// 이미 가족이면
	if (A_parent == B_parent) return;
	else {
		// 더 작은놈을 부모라 하자
		int Min = min(A_parent, B_parent);
		int Max = max(A_parent, B_parent); 
		Parent[Max] = Min; // 너도 자식이 되라
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
			int answer = Find_Parent(now); // 부모를 찾고
			cout << Sum[answer] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	for (int i = 1; i < MAX; i++) {
		Parent[i] = i; // 자기자신
		Sum[i] = 1; // 기본값은 부품이 1개필요
	}

	input();

	return 0;
}