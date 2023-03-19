#include<iostream>

//1. 전체가 같은 문자로 이루어진 문자열인지 판별한다. 2. 펠린드롬인지 아닌지 투포인터로 확인한다.
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	long long left, right;
	bool palindrome = true;
	bool sameChar = true;

	cin >> s;

	long long size = s.length();

	left = 0;
	right = size - 1;

	while (left < right) {
		if (s[left] != s[right]) {
			palindrome = false;
			break;
		}
		left++;
		right--;
	}

	if (!palindrome) {
		cout << size;
	}
	else {
		for (long long i = 0; i < size-1; i++) {
			if (s[i] != s[i+1]) {
				sameChar = false;
				break;
			}
		}
		if (sameChar)
			cout << -1;
		else
			cout << size - 1;
	}

}