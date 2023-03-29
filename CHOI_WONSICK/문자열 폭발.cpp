#include <cstring>
#include <iostream>
#include <string>
using namespace std;

char temp[1000000];
int main() {  // 입력받은 다음에 앞에부터 비교하면서 boom의 마지막과 문자열 temp와 같다면 idx가
              // boom 의 길이만큼 돌아오기.
    string str;
    string boom;
    cin >> str;
    cin >> boom;

    char last_boom = boom[boom.length() - 1];  // 폭발문자열의 맨 마지막 문자. (요걸로 비교할거임)
    int top = 0;

    for (int i = 0; i < str.length(); i++) {
        if (top + 1 < boom.length()) {  // top은 1이 1개
            temp[top++] = str[i];
            continue;
        }

        temp[top++] = str[i];
        bool flag = true;
        if (temp[top - 1] == last_boom) {
            for (int j = 0; j < boom.length(); j++) {
                if (temp[top - 1 - j] != boom[boom.length() - 1 - j]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                top = top - boom.length();
            }
        }
        // cout<<temp<<'\n';
    }

    if (top > 1) {
        for (int i = 0; i < top; i++) {
            cout << temp[i];
        }
    } else
        cout << "FRULA";
}
