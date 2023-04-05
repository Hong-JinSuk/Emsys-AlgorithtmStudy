#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

//재귀 방식의 풀이
string s;
bool clear = false;
int sSize;

void recur(string a) {
	if (clear)
		return;
	string temp;
	if (a.length() > sSize) {
		if (a.back() == 'A') {
			temp = a;
			temp.pop_back();
			if (temp == s) {
				clear = true;
				return;
			}
			recur(temp);
		}
		if (a.back() == 'B') {
			a.pop_back();
			reverse(a.begin(), a.end());
			if (a == s) {
				clear = true;
				return;
			}
			recur(a);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string t;

	cin >> s >> t;
	sSize = s.length();
	recur(t);
	if (clear)
		cout << 1;
	else
		cout << 0;
}


//bfs 풀이
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	bool clear = false, finished = false;
//	int sSize, size, sLen, tLen;
//	string s, t, temp, op;
//	cin >> s >> t;
//	sLen = s.length();
//	queue<string> bfsQ;
//	bfsQ.push(t);
//
//	while (!finished && !bfsQ.empty()) {
//		size = bfsQ.size();
//		for (int i = 0; i < size; i++) {
//			// test code
//			//cout << "operate for " << bfsQ.back() << "\n";
//
//			temp = bfsQ.back();
//
//			//test code
//			//cout << "temp : " << temp << "\n";
//
//			if (temp.back() == 'A' && temp.length() > sLen) {
//				// test code
//				//cout << "op1 valid. ";
//
//				op = temp;
//				op.pop_back();
//
//				//test code
//				//cout << "new t : " << op << "\n";
//
//				if (op == s) {
//					//test code
//					//cout << "find s\n";
//
//					clear = true;
//					finished = true;
//					break;
//				}
//				bfsQ.push(op);
//			}
//			if (temp.back() == 'B' && temp.length() > sLen) {
//				//test code
//				//cout << "op2 valid. ";
//
//				op = temp;
//				op.pop_back();
//				reverse(op.begin(), op.end());
//
//				//test code
//				//cout << "new t : " << op << "\n";
//
//				if (op == s) {
//					//test code
//					//cout << "find s\n";
//
//					clear = true;
//					finished = true;
//					break;
//				}
//				bfsQ.push(op);
//			}
//			bfsQ.pop();
//		}
//	}
//
//	if (clear)
//		cout << 1;
//	else
//		cout << 0;
//}
