#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

int testcase, n, child1, child2, Parent;

void maketree(int n, int* Node) {

	int p, c; // p : parent, c : child

	for (int i = 0; i < n - 1; i++) {
		cin >> p >> c;
		Node[c] = p; // Node[child]=parent, 자식의 부모는 하나라 이렇게해도됌
	}
}

void SearchParent(int* Node, int child, bool* isParent) {
	if (isParent[Node[child]]) { // 만약 겹치는 부모를 찾았을 경우
		Parent = Node[child];
		return; // 더이상 안찾아도 된다.
	}
	else if (Node[child] != 0) { // 부모가 존재한다면 ( Root까지 찾아감 )
		isParent[Node[child]] = true; // child의 부모들을 모두 check
		SearchParent(Node, Node[child], isParent); // 부모의 부모를 찾아간다.
	}
	else return;
}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> n;

		int Node[10001];
		for (int i = 0; i < 10001; i++) {
			Node[i] = 0; // 초기화
		}

		maketree(n, Node); // 트리 완성
		
		bool isSameParent[10001];
		for (int i = 0; i < 10001; i++) {
			isSameParent[i] = false; //초기화
		}

		cin >> child1 >> child2;
		isSameParent[child1] = true;
		isSameParent[child2] = true;
		SearchParent(Node, child1, isSameParent);
		SearchParent(Node, child2, isSameParent);

		if (child1 == child2) {
			cout << child1 << endl;
			return 0;
		}
		cout << Parent << endl;
	}
	return 0;
}