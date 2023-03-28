#include <iostream>

using namespace std;

char arr[1000000];
 // 폭발할 문자열과 현재 저장한 문자열의 끝에있는 문자열을 비교 
bool compare(string key, int p) {
	string a = ""; // 비교할 문자열 생성
	for (int i = key.length(); i > 0; i--) {
		a += arr[p - i];
	}
	if (a == key) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string temp, key; // key - 폭발 문자열, temp - 탐색할 문자열
	cin >> temp >> key;
	int p = 0; // 문자열의 개수를 확인할 변수
    
	// 문자열을 처음부터 끝까지 탐색 
	for (int i = 0; i < temp.length(); i++) {
		arr[p++] = temp[i];
		if (p >= key.length()) {
			if (compare(key, p)) // 만약 문자열의 끝이 폭발 문자열인 경우
		 		p -= key.length(); // 폭파 
		}
	}

	if (!p) // 남아있는 문자열의 개수 확인 
		cout << "FRULA\n";
	else { // 남아있는 문자열 존재하므로 출력
		for (int i = 0; i < p; i++) {
			cout << arr[i];
		}
		cout << '\n';
	}


	return 0;
}
