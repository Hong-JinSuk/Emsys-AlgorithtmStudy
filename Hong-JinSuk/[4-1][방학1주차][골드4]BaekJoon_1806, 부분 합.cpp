#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

int N, S;
vector<int> arr;

int search() {

	if (arr[0] == S) return 1;

	int l_p = 0;
	int r_p = 1;

	int sum = arr[0];
	int len = 100001;
	while (l_p <= r_p) {
		int Sum = sum + arr[r_p];
		if (Sum < S) {
			sum += arr[r_p];
			r_p++;
		}
		else if (Sum >= S) {
			len = min(len, r_p - l_p + 1);
			sum -= arr[l_p];
			l_p++;
		}

		if (r_p == arr.size()) break;
	}

	if (l_p == 0 && r_p == arr.size()) return 0;

	return len;
}

int main() {

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	cout << search();

	return 0;
}