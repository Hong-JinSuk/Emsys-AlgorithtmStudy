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
		arr.push_back(String[i]); // ���ڿ��� �� �� ���ں��� �־���.
		if (String[i] == Pop.back()) { // ���߹��� ������ �ڸ��� ���� ���ڰ� ������
			if (com()) { // �ű⼭���� ���߹��ΰ� �˻��Ѵ�
				for (int j = 0; j < len; j++) {
					arr.pop_back(); // ���߹��̸� �����ش�.
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

// �Ʒ��� �ð��ʰ� �ڵ�

//void Find() {
//
//	while (String.find(Pop) != string::npos) { // ���߹��� ���� ������ �ݺ�
//
//		int Index = String.find(Pop, start); // Index�� start �������� Ž���ؼ� ���߹���ã�� ��ġ
//
//		String.erase(Index, len); // Index ���� len(���߹��� ����)��ŭ ����
//
//		start = Index - len; // �������� ���߹��� ���̸�ŭ �ڷ� �����.
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
//	len = Pop.size(); // len = ���߹� ����
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