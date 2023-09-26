#include<iostream>
#include<vector>
using namespace std;

struct bNode {
	vector<int> index;
	int size;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, bomb; //입력 문자열, 폭발 문자열
	int lastS, sLen, bLen; //문자열의 남은 길이, 입력 문자열과 폭발 문자열의 길이
	cin >> s >> bomb;
	sLen = s.length();
	lastS = sLen;
	bLen = bomb.length();
	vector<bool> exist(sLen, true); //문자열 출력할때 쓸 배열(폭발하면 false로 바뀜. 마지막에 true면 해당 문자는 출력함)
	vector<bNode> bStack; //폭발문자열 누적되는 스택

    
    if(bLen == 1){ //폭발문자열의 길이가 1인 경우 - 이거때문에 반례 걸렸었음
        for (int i = 0; i < sLen; i++) {//근데 처리는 진짜 간단함
		    if (s[i] == bomb[0]) {
			    exist[i] = false;
				lastS--;
            }
        }
    }
    
    else{//폭발문자열의 길이가 2이상인 경우
	    for (int i = 0; i < sLen; i++) {//s의 앞에서부터 끝까지 한번씩만 체크
	    	if (s[i] == bomb[0]) { //새 폭발문자열 발견시 push
	    		vector<int> newIndex(bLen, 0);
	    		bStack.push_back({ newIndex, 1 });
	    		bStack.back().index[0] = i;
	    	}
	    	else if (!bStack.empty() && s[i] == bomb[bStack.back().size]) { //top에서 탐색중인 폭발문자열의 다음 글자와 s[i]가 같다면 
	    		bStack.back().index[bStack.back().size++] = i;
	    		if (bStack.back().size == bLen) {//끝까지 왔으면
	    			for (int j = 0; j < bLen; j++) { //해당 폭발문자열이
	    				exist[bStack.back().index[j]] = false; //폭발하며 지워진다.
	    			}
	    			bStack.pop_back();
	    			lastS -= bLen;
	    		}
	    	}
	    	else {//새 글자가 기존 폭발문자열에서 이어지지도 않고, 새 폭발문자열의 시작도 아니라면
	    		if(!bStack.empty())//스택에 뭐가 남아있는 경우
	    			bStack.clear();//지금까지의 모든 폭발문자열이 의미없어지므로 다 지워진다. 
	    	}
	    }
    }
	if (!lastS)//남아있는 문자의 개수가 0인 경우
		cout << "FRULA";
	else {//남아있는 문자의 개수가 1이상인 경우
		for (int i = 0; i < sLen; i++) {
			if (exist[i])
				cout << s[i];
		}
	}
}
