#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct node {
	string str;
	bool right;
};

bool flip(bool a) {
	if (a)
		a = false;
	else
		a = true;
	return a;
}

queue<node>bfsQ;

bool sameCheck(string a, string b) { //a가 짧거나 같은애(s), b가 긴 애(t)
	bool same = false;
	int aSize = a.length();
	int bSize = b.length();
	int lastStart = bSize - aSize;
	for (int i = 0; i <= lastStart; i++) { //정방향 검사
		if (same)
			break;
		for (int j = 0; j < aSize; j++) {
			if (a[j] != b[i + j])
				break;
			if (j == aSize - 1)
				same = true;
		}
	}
	for (int i = 0; i <= lastStart; i++) { //역방향 검사
		if (same)
			break;
		for (int j = 0; j < aSize; j++) {
			if (a[j] != b[bSize - 1 - i - j])
				break;
			if (j == aSize-1)
				same = true;
		}
	}
	return same;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count, temp;
	bool clear = false;
	string s, t;
	cin >> s >> t;

	count = t.length() - s.length();

	if (sameCheck(s, t)) {
		//test code
		//cout << "s is exist in t. push s\n";

		bfsQ.push({ s, 1 });
	}
	else {
		//test code
		//cout << "s is not exist in t\n";

		cout << 0;
		return 0;
	}

	for (int i = 0; i < count; i++) {
		//test code
		//cout << "i is " << i << ". bfsQ's size is " << bfsQ.size() << ". lets do operate 1 and 2\n";

		temp = bfsQ.size();
		for (int j = 0; j < temp; j++) {
			string tempStr = bfsQ.front().str;
			bool tempDir = bfsQ.front().right;
			//right == true면 오른쪽에 붙이기. false면 왼쪽에 붙이기. B연산 시 right 바꿔주기.
			if (tempDir) {//정방향일 때
				if (sameCheck(tempStr + "A", t))
					bfsQ.push({ tempStr + "A", tempDir });
				if (sameCheck(tempStr + "B", t))
					bfsQ.push({ tempStr + "B", flip(tempDir) });
			}
			else { //역방향일 때
				if (sameCheck("A" + tempStr, t))
					bfsQ.push({ "A" + tempStr, tempDir});
				if (sameCheck("B" + tempStr, t))
					bfsQ.push({ "B" + tempStr, flip(tempDir)});
			}
			bfsQ.pop();

			//test code
			//cout << "search for " << i << " is end. bfsQ's new item : " << bfsQ.size() + 1 - temp << "\n";

		}
	}
	//최종 결과물 중 t와 같은 애가 있으면 큐에 한개 혹은 두개(좌우대칭일 경우)가 남아있을 것. 마지막으로 방향이 같은지만 확인

	int qSize = bfsQ.size();
	for (int i = 0; i < qSize; i++) {
		if (clear)
			break;
		temp = t.length();
		if (bfsQ.front().right) {
			for (int j = 0; j < temp; j++) {
				if (bfsQ.front().str[j] != t[j])
					break;
				if (j == temp - 1)//전부 같아서 break에 걸리지 않고 temp-1번 인덱스까지 통과했을 경우 같은문자열
					clear = true;
			}
			bfsQ.pop();
		}
		else {
			for (int j = 0; j < temp; j++) {
				if (bfsQ.front().str[j] != t[temp-1-j])
					break;
				if (j == temp - 1)//전부 같아서 break에 걸리지 않고 temp-1번 인덱스까지 통과했을 경우 같은문자열
					clear = true;
			}
			bfsQ.pop();
		}
	}
	if (clear)
		cout << 1;
	else
		cout << 0;

	return 0;
}
