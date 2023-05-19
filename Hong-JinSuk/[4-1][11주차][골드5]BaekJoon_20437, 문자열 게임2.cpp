#include<iostream>
#include<vector>
#include<cmath>
#define endl "\n"
using namespace std;

string w;
int k;

int shortcase(string w, int k) {

	vector<int> alphabet[27]; // alpha[1]=a , ... alpha[26]=z
	int result = 99999;

	for (int i = 0; i < w.size(); i++) {
		int index = w[i] - 'a' + 1; // w[0] = b 라면 index = 2 
		//cout << "index : " << index << ", w :" << w[i] << endl;
		if (alphabet[index].size() + 1 >= k) { // 이번에 넣어서 k개 이상이 된다면
			// 만약 길이가 갱신이 된다면 해준다.
			alphabet[index].push_back(i);
			result = min(result, alphabet[index][alphabet[index].size() - 1] - alphabet[index][alphabet[index].size() - k]);
		}
		else { // 이번에 넣어도 k개를 아직 포함하지 못한다면,
			alphabet[index].push_back(i); // b가 0번째에 존재함을 넣어줌.
		}
	}

	return result + 1;
}

int longcase(string w, int k) {
	vector<int> alphabet[27]; // alpha[1]=a , ... alpha[26]=z
	int result = 0;

	for (int i = 0; i < w.size(); i++) {
		int index = w[i] - 'a' + 1; // w[0] = b 라면 index = 2 
		if (alphabet[index].size() + 1 >= k) { // 이번에 넣어서 k개 이상이 된다면
			alphabet[index].push_back(i);
			result = max(result, alphabet[index][alphabet[index].size() - 1] - alphabet[index][alphabet[index].size() - k]);
		}
		else {
			alphabet[index].push_back(i);
		}
	}
	return result + 1;
}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> w >> k;
		if (k == 1) {
			cout << 1 << " " << 1 << endl;
			continue;
		}
		
		if (shortcase(w, k) == 100000 || longcase(w, k) == 100000) cout << -1 << endl;
		else cout << shortcase(w, k) << " " << longcase(w, k) << endl;
	}

	return 0;
}