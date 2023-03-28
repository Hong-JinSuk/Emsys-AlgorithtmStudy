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

// 아래 코드는 S에서 넣는 방식

//void PushWord(char Word) {
//
//	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//
//	//cout << "Push : " << Word << endl;
//	// A or B 가 들어왔을 때, 넣을 수 있는 방법들
//	if (Word == 'A') {
//		cnt_A--;
//		if (isReverse) ans.push_front('A');
//		else ans.push_back('A');
//	}
//	else {
//		cnt_B--;
//		if (isReverse) {
//			ans.push_front('B');
//			isReverse = false; // 다시 뒤집어준다.
//		}
//		else {
//			ans.push_back('B');
//			isReverse = true; // 뒤집어준다.
//		}
//	}
//	depth++; // 한층 내려감
//
//	// 만약 A나 B의 갯수가 넘어가면 중단한다.
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
//	if (depth == (t_len - s_len)) { // 다 반복 했다면 비교해준다.
//
//		for (int i = 0; i < t_len; i++) {
//			if (isReverse) {
//				if (ans[i] != T[t_len - 1 - i]) break; // 하나라도 틀리면 안된다.
//			}
//			else if (ans[i] != T[i]) break; // 하나라도 틀리면 안된다.
//
//			if (i == t_len - 1) canMake = true; // 모두 같다면 만들 수 있다.
//		}
//
//		depth--; // 한 단계 뒤로
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
//		return; // 끝낸다.
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
//	depth--; // 한 단계 뒤로
//	return;
//}
//
//int main() {
//
//	cin >> S >> T;
//	s_len = S.size();
//	t_len = T.size();
//
//	// 시간초과 때문에 A or B의 갯수가 넘어가면 중단하게 함.
//	// ex) S=A, T=BBBBBBBBBBBBBBBBBBBAA 의 경우 A가 두번 들어가면 다시 돌아옴
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

// 이 식이 push or pop 하는 기준
// input	A	B	A	B
//  re		X	X	O	O
//	pop		b	f	f	b

//BB
//BBAA

//BBB
//BABBB

//BBB
//BBBAA