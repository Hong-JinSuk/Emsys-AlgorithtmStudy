#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

int testcase, n, child1, child2, Parent;

void maketree(int n, int* Node) {

	int p, c; // p : parent, c : child

	for (int i = 0; i < n - 1; i++) {
		cin >> p >> c;
		Node[c] = p; // Node[child]=parent, �ڽ��� �θ�� �ϳ��� �̷����ص���
	}
}

void SearchParent(int* Node, int child, bool* isParent) {
	if (isParent[Node[child]]) { // ���� ��ġ�� �θ� ã���� ���
		Parent = Node[child];
		return; // ���̻� ��ã�Ƶ� �ȴ�.
	}
	else if (Node[child] != 0) { // �θ� �����Ѵٸ� ( Root���� ã�ư� )
		isParent[Node[child]] = true; // child�� �θ���� ��� check
		SearchParent(Node, Node[child], isParent); // �θ��� �θ� ã�ư���.
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
			Node[i] = 0; // �ʱ�ȭ
		}

		maketree(n, Node); // Ʈ�� �ϼ�
		
		bool isSameParent[10001];
		for (int i = 0; i < 10001; i++) {
			isSameParent[i] = false; //�ʱ�ȭ
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