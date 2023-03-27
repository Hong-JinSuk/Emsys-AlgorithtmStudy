#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

string String;
string Pop;
vector<char> arr;

int len;

bool com() {
	for (int i = 0; i < len; i++) {
		if (Pop[i] != arr[arr.size() - len + i]) return false;
	}
	return true;
}

int main() {

	cin >> String >> Pop;
	len = Pop.size();

	for (int i = 0; i < String.size(); i++) {
		arr.push_back(String[i]); // 문자열의 맨 앞 문자부터 넣어줌.
		if (String[i] == Pop.back()) { // 폭발물의 마지막 자리와 같은 문자가 들어오면
			if (com()) { // 거기서부터 폭발물인가 검사한다
				for (int j = 0; j < len; j++) {
					arr.pop_back(); // 폭발물이면 빼내준다.
				}
			}
		}
	}

	if (arr.size() == 0) cout << "FRULA"; 
	else {
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i];
	}

	return 0;
}

// 아래는 시간초고가 코드

//void Find() {
//
//	while (String.find(Pop) != string::npos) { // 폭발물이 없을 때까지 반복
//
//		int Index = String.find(Pop, start); // Index는 start 지점부터 탐색해서 폭발물을찾은 위치
//
//		String.erase(Index, len); // Index 부터 len(폭발물의 길이)만큼 삭제
//
//		start = Index - len; // 시작점을 폭발물의 길이만큼 뒤로 늦춘다.
//
//		if (start < 0) start = 0;
//
//	}
//	
//}
//
//int main() {
//
//	cin >> String >> Pop;
//	len = Pop.size(); // len = 폭발물 길이
//	
//	Find();
//	
//	if (String.size() == 0) {
//		cout << "FRULA";
//	}
//	cout << String;
//
//
//
//	return 0;
//}