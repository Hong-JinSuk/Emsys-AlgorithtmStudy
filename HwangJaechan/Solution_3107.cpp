#include <iostream>
#define MAX 41

using namespace std;

void sol(string s) {
	int start = s.find("::");
	int cup = -1,k=0,temp =0;
	char arr[MAX] = { 0 };
	if (start == -1) start = s.length()-1;
	for (int i = 0; i <= start; i++) {
		if (s[i] != ':' && i!=s.length()-1)continue;
		if (i == s.length() - 1) i++;
		for (int j = 0; j < 4 - (i - cup-1); j++) {
			arr[k++] = '0';
		}
		
		for (int j = cup + 1; j < i; j++) {
			arr[k++] = s[j];
		}
		cup = i;
	}
	temp = k;
	k = 31;
	cup = s.length();
	for (int i = s.length()-1; i >= start+1; i--) {
		if (s[i] != ':')continue;
		for (int j = cup-1; j > i; j--) {
			arr[k--] = s[j];
		}
		for (int j = 0; j < 4 - (cup - i-1); j++) {
			arr[k--] = '0';
		}
		cup = i;
	}
	for (int i = temp; i <= k; i++) {
		arr[i] = '0';
	}
	for (int i = 0; i < 32; i++) {
		cout << arr[i];
		if (i % 4 == 3 && i!=31) cout << ':';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	sol(s);
	
	return 0;
}
