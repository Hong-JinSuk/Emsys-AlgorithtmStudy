#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;  // 사전 담을배열
int n;
string ori;       // 처음 들어갈 문자열
int maximum = 0;  // 가장큰 문자열 초기화하는 함수
string result;    // 가장큰 문자열 담을 변수
int idx;          // 사전을 길이대로 sort 시켜놓았기때문에, 큐에들어가는 문자열의 길이는, 큐에서 일찍 pop 될 수록 작거나 같다.

bool compare(string a, string b) { return a.length() < b.length(); }  // quick sort의 컴페어 함수, 문자열 길이를 기준으로 오름차순 으로 만듬

void analyze_max(string a) {  // string a 를 넣어서 맥시멈 값과 가장 큰 문자열을 변수에 각각 입력.
    if (int(a.length()) > maximum) {
        maximum = a.length();
        result = a;
    }
}

void bfs() {
    queue<string> que;
    que.push(ori);

    while (!que.empty()) {
        string cur = que.front();
        que.pop();
        while (cur.length() >= vec[idx].length() && idx < vec.size()) idx++;  // vec[idx] 가 vec 의 사이즈보다 작고 현재 cur의 문자열 길이보다 작거나 같으면 idx++
        for (int i = 97; i <= 122; i++) {                                     // 아스키 코드 a~z를 문자열 temp에다가 넣어줌.
            string temp;                                                      // cur을 바꾸지않고 일단 temp에 저장해서 그걸바꿔서 비교할거임
            for (int j = 0; j <= cur.length(); j++) {                         // 현재 cur의 인덱스 곳곳마다 알파벳 하나씩 넣어볼거임
                temp = cur;
                string a;                                                                     // 여거 temp 에 넣어줄거
                a = char(i) + '\0';                                                           // i 를 string 으로 만들어주려면 이렇게 해야댐
                temp.insert(j, a);                                                            // temp 는 a~z를 각 인덱스에 한번씩 넣어본 모든경우의 수의 문자열입니다.
                for (int k = idx; temp.length() == vec[k].length() && k < vec.size(); k++) {  // temp의 길이보다 vec의 idx 에있는 문자 길이가 같으면 계속진행
                    if (temp == vec[k]) {                                                     // 만약 찾는값이 벡터에있다면
                        que.push(temp);                                                       // 큐에푸쉬
                        analyze_max(temp);                                                    // 가장큰지확인.
                    }
                }
                if (idx >= vec.size()) break;  // 만약 idx가 벡터사이즈보다 크다면 브릭.
            }
        }
    }
}

int main() {
    cin >> n >> ori;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end(), compare);  // 오름차순정렬
    bfs();
    cout << result;
}// 예제출력은 잘 되는데 4프로에서 틀렸다고뜹니다..
