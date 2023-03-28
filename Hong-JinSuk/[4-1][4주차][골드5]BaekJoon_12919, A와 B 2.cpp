#include<iostream>
#include<algorithm>
#include<deque>
#define endl "\n"
using namespace std;

bool isReverse;
bool canMake;
string S, T;
deque<char> ans;
int s_len, t_len, depth, cnt_A, cnt_B;

void POP(deque<char> ans) {

	if (ans.size() == s_len) {
		for (int i = 0; i < s_len; i++) {
			if (S[i] != ans[i]) break;
			if (i == s_len - 1) canMake = true;
		}
	}

	if (s_len > ans.size()) return;

	if (ans.back() == 'A') {
		deque<char> ans2(ans);
		ans2.pop_back();
		POP(ans2);
	}

	if (ans.front() == 'B') {
		deque<char> ans2(ans);
		reverse(ans2.begin(), ans2.end());
		ans2.pop_back();
		POP(ans2);
	}

	return;
}

int main() {

	cin >> S >> T;

	t_len = T.size();
	s_len = S.size();
	for (int i = 0; i < t_len; i++)
		ans.push_back(T[i]);

	POP(ans);
	if (canMake) cout << 1;
	else cout <<0;
	return 0;
}

// �Ʒ� �ڵ�� S���� �ִ� ���

//void PushWord(char Word) {
//
//	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//
//	//cout << "Push : " << Word << endl;
//	// A or B �� ������ ��, ���� �� �ִ� �����
//	if (Word == 'A') {
//		cnt_A--;
//		if (isReverse) ans.push_front('A');
//		else ans.push_back('A');
//	}
//	else {
//		cnt_B--;
//		if (isReverse) {
//			ans.push_front('B');
//			isReverse = false; // �ٽ� �������ش�.
//		}
//		else {
//			ans.push_back('B');
//			isReverse = true; // �������ش�.
//		}
//	}
//	depth++; // ���� ������
//
//	// ���� A�� B�� ������ �Ѿ�� �ߴ��Ѵ�.
//	if (cnt_A < 0 || cnt_B < 0) {
//		//cout << "Back////////////////////////\n";
//		if (Word == 'A' && !isReverse) {
//			//cout << "pop : " << ans.back() << endl;
//			cnt_A++;
//			ans.pop_back();
//		}
//		else if (Word == 'B' && !isReverse) {
//			//cout << "pop : " << ans.front() << endl;
//			cnt_B++;
//			isReverse = true;
//			ans.pop_front();
//		}
//		else if (Word == 'A' && isReverse) {
//			//cout << "pop : " << ans.front() << endl;
//			cnt_A++;
//			ans.pop_front();
//		}
//		else {
//			//cout << "pop : " << ans.back() << endl;
//			cnt_B++;
//			isReverse = false;
//			ans.pop_back();
//		}
//		depth--;
//		return;
//	}
//
//	if (depth == (t_len - s_len)) { // �� �ݺ� �ߴٸ� �����ش�.
//
//		for (int i = 0; i < t_len; i++) {
//			if (isReverse) {
//				if (ans[i] != T[t_len - 1 - i]) break; // �ϳ��� Ʋ���� �ȵȴ�.
//			}
//			else if (ans[i] != T[i]) break; // �ϳ��� Ʋ���� �ȵȴ�.
//
//			if (i == t_len - 1) canMake = true; // ��� ���ٸ� ���� �� �ִ�.
//		}
//
//		depth--; // �� �ܰ� �ڷ�
//
//		if (Word == 'A' && !isReverse) {
//			//cout << "pop : " << ans.back() << endl;
//			cnt_A++;
//			ans.pop_back();
//		}
//		else if (Word == 'B' && !isReverse) {
//			//cout << "pop : " << ans.front() << endl;
//			cnt_B++;
//			isReverse = true;
//			ans.pop_front();
//		}
//		else if (Word == 'A' && isReverse) {
//			//cout << "pop : " << ans.front() << endl;
//			cnt_A++;
//			ans.pop_front();
//		}
//		else {
//			//cout << "pop : " << ans.back() << endl;
//			cnt_B++;
//			isReverse = false;
//			ans.pop_back();
//		}
//
//		return; // ������.
//	}
//
//	PushWord('A');
//	PushWord('B');
//
//	if (Word == 'A' && !isReverse) {
//		//cout << "pop : " << ans.back() << endl;
//		cnt_A++;
//		ans.pop_back();
//	}
//	else if (Word == 'B' && !isReverse) {
//		//cout << "pop : " << ans.front() << endl;
//		cnt_B++;
//		isReverse = true;
//		ans.pop_front();
//	}
//	else if (Word == 'A' && isReverse) {
//		//cout << "pop : " << ans.front() << endl;
//		cnt_A++;
//		ans.pop_front();
//	}
//	else {
//		//cout << "pop : " << ans.back() << endl;
//		cnt_B++;
//		isReverse = false;
//		ans.pop_back();
//	}
//	depth--; // �� �ܰ� �ڷ�
//	return;
//}
//
//int main() {
//
//	cin >> S >> T;
//	s_len = S.size();
//	t_len = T.size();
//
//	// �ð��ʰ� ������ A or B�� ������ �Ѿ�� �ߴ��ϰ� ��.
//	// ex) S=A, T=BBBBBBBBBBBBBBBBBBBAA �� ��� A�� �ι� ���� �ٽ� ���ƿ�
//	cnt_A = 0;
//	cnt_B = 0;
//
//	for (int i = 0; i < t_len; i++) {
//		if (T[i] == 'A') cnt_A++;
//		else cnt_B++;
//	}
//
//	for (int i = 0; i < s_len; i++) {
//		if (S[i] == 'A') cnt_A--;
//		else cnt_B--;
//	}
//
//	for (int i = 0; i < s_len; i++) {
//		ans.push_back(S[i]);
//	}
//
//	depth = 0;
//
//	PushWord('A');
//	PushWord('B');
//
//	if (canMake) cout << 1;
//	else cout << 0;
//
//	return 0;
//}

// �� ���� push or pop �ϴ� ����
// input	A	B	A	B
//  re		X	X	O	O
//	pop		b	f	f	b

//BB
//BBAA

//BBB
//BABBB

//BBB
//BBBAA