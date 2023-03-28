#include <iostream>
#include <vector>

using namespace std;

string funA(string b) {
	string a = b;
	a.erase(a.length() - 1);
	return a;
}

string funB(string b) {
	string a = b;
	for (int i = 0; i < a.length() / 2; i++) {
		swap(a[i], a[a.length() - 1 - i]);
	}
	a.erase(a.length() - 1);
	return a;
}

int sol(string a,string b) {
	vector<string>arr;
	vector<string>temp;
	int j, k = 1;
	arr.push_back(b);
	while (k) {
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (a == arr[i])
				return 1;
			if (arr[i].length() == 0)
				return 0;
			if (arr[i][0] == 'B') {
				temp.push_back(funB(arr[i]));
				k++;
			}
			if (arr[i][arr[i].length() - 1] == 'A') {
				temp.push_back(funA(arr[i]));
				k++;
			}
		}
		arr.clear();
		for (int i = 0; i < k; i++) {
			arr.push_back(temp[i]);
		}
		temp.clear();
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a,b; // a는 원형 b는 목표
	cin >> a >> b;

	cout << sol(a, b);

	return 0;
}
