#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t,n;
	cin >> t;
	for (int k = 0; k < t; k++) {
		string a;
		cin >> a >> n;
		vector<int>alpha[26];
		for (int i = 0; i < a.length(); i++) {
			alpha[a[i] - 'a'].push_back(i);
		}
		int i = 0, j = a.length()-1;
		bool flag = 0;
		int maxi = 0, mini = 10000;
		for (int i = 0; i < 26; i++) {
			if (alpha[i].size() >= n) {
				flag = 1;
				for (int j = 0; j < alpha[i].size(); j++) {
					if (j + n - 1 >= alpha[i].size())break;
					mini = min(mini, alpha[i][j + n - 1] - alpha[i][j] + 1);
					maxi = max(maxi, alpha[i][j + n - 1] - alpha[i][j] + 1);
				}
			}
		}
		if (flag)
			cout << mini << ' ' << maxi << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}
