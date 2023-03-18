#include<iostream>
using namespace std;

string pal;

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> pal;

	// 모든 문자가 같으면 -1 반환
	bool isSame = true;
	for (int i = 0; i < pal.size() - 1; i++) {
		if (pal[i] != pal[i + 1]) isSame = false;
	}
	if (isSame) {
		cout << -1;
		return 0;
	}

	// 회문이면 전체 길이-1, 회문이 아니면 전체 길이 반환
	int Size = pal.size() / 2;
	int palSize = pal.size();
	bool isPal = true;
	for (int i = 0; i < Size; i++) {
		if (pal[i] != pal[--palSize]) isPal = false;
	}
	if (isPal) {
		cout << pal.size() - 1;
		return 0;
	}
	else {
		cout << pal.size();
		return 0;
	}

	return 0;
}