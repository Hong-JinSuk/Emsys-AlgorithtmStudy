#include <iostream>

using namespace std;

string bigwait;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s, wait = "";
	while (cin >> s) {
		if (s == "<br>") {
			bigwait += wait + "\n";
			wait = "";
		}
		else if (s == "<hr>") {
			if (wait == "") {
				bigwait += "--------------------------------------------------------------------------------\n";
			}
			else {
				bigwait += wait + "\n--------------------------------------------------------------------------------\n";
			}
			wait = "";
		}
		else if (wait.length() + s.length() >= 80) {
			bigwait += wait + "\n";
			wait = s;
		}
		else {
			if (wait == "") wait = s;
			else wait += " " + s;
		}
	}
	cout << bigwait << wait;
}
