#include <iostream>
#include <vector>

using namespace std;
/*두 가지 연산을 원형에서 시작하게되면 경우의 수가 최대 2^49이므로 메모리 초과가 날 수 밖에 없어 백 트래킹을 이용하여야 한다. 
*/
string funA(string b) {  // 맨뒤에서 A를 삭제하는 연산
	string a = b;
	a.erase(a.length() - 1);
	return a;
}

string funB(string b) { // reverse를 해준 후 B를 삭제하는 연산
	string a = b;
	for (int i = 0; i < a.length() / 2; i++) {
		swap(a[i], a[a.length() - 1 - i]);
	}
	a.erase(a.length() - 1);
	return a;
}

int sol(string a,string b) { // a 는 원형 b는 목표값 그러므로 b를 원형으로 백트레킹하는 과정
	vector<string>arr;
	vector<string>temp;
	int j, k = 1;
	arr.push_back(b);
	while (k) { // bfs를 이용하여 b를 a로 만들어준다.
		j = k;
		k = 0;
		for (int i = 0; i < j; i++) {
			if (a == arr[i])
				return 1;
			if (arr[i].length() == 0) //arr[i]의 길이가 0이라는 것은 모든 arr속 문자열이 공백이라는 것
				return 0;
			if (arr[i][0] == 'B') { // 첫번째가 B라면 B를 추가해준 후 리버스를 해준 것과 같기 때문에 funB사용
				temp.push_back(funB(arr[i]));
				k++;
			}
			if (arr[i][arr[i].length() - 1] == 'A') { // 마지막이 A라면 A를 그냥 추가해준 연산을 했을 것이므로 funA사용
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
