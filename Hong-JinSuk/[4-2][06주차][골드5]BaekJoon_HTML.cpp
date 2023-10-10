#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string str;
	string HR = "--------------------------------------------------------------------------------";
	int isStart = 0;

	while (1) {
		cin >> str;
		if (cin.eof() == true) break;

		if (str == "<br>") {
			cout << endl;
			isStart = 0;
		}
		else if (str == "<hr>") {
			if (isStart == 0) cout << HR << endl;
			else cout << endl << HR << endl;
			isStart = 0;
		}
		else {
			if (isStart + str.size() + 1 < 80) {
				if (isStart == 0) {
					cout << str;
					isStart += str.size();
				}
				else {
					cout << " " << str;
					isStart += str.size() + 1;
				}
			}
			else {
				cout << endl << str;
				isStart = str.size();
			}
		}
	}
	return 0;
}