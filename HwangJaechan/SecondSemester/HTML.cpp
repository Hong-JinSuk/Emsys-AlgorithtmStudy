#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX 1000000001
#define INF 100000000001

using namespace std;
using lld = long long;

vector<string>strings;

void sol() {
	string r = "";
	for (int i = 0; i < strings.size(); i++) {
		if (strings[i] == "<br>") {
			cout << r << '\n';
			r = "";
		}
		else if (strings[i] == "<hr>") {
			if (r.size()) {
				cout << r << '\n';
				r = "";
			}
			for (int j = 0; j < 80; j++) {
				cout << '-';
			}
			cout << '\n';
		}
		else if (r.size() + strings[i].size() >= 80) {
			cout << r << '\n';
			r = strings[i];
		}
		else {
			if (r.size())r += ' ' + strings[i];
			else r = strings[i];
		}
	}
	cout << r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string k = "";
	while (1) {
		cin >> k;
		if (cin.eof()) break;
		strings.push_back(k);
	}

	sol();

	return 0;
}
