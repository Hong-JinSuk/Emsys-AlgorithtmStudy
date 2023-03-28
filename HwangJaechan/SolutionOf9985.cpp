#include <iostream>

using namespace std;

char arr[1000000]; // 스택용 char type araay

bool compare(string key, int p) { // 폭발할 문자열이 존재하는지 확인
	string a = "";
	for (int i = key.length(); i > 0; i--) {
		a += arr[p - i];
	}
	if (a == key)
		return 1;
	else
		return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string ans, key;
	cin >> ans >> key;
	int p = 0;
	
	for (int i = 0; i < ans.length(); i++) { // 하나씩 arr에 넣어주면서 문자열 폭파
		arr[p++] = ans[i];
		if (p >= key.length()) {
			if (compare(key, p))
				p -= key.length();
		}
	}

	if (!p) // 만약 p가 0이라면 남아있는 문자가 없으므로 FRULA 출력 
		cout << "FRULA\n";
	else {
		for (int i = 0; i < p; i++) { // 그렇지 않다면 남은 문자열 출력.
			cout << arr[i];
		}
		cout << '\n';
	}
	

	return 0;
}
