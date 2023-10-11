#include<iostream>
#include<string>
#include <vector>

using namespace std;

int main() {
    vector<string> v;
    string word;
    while (cin >> word) {
        v.push_back(word);
    }
    int str_length = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "<br>") {// <br> 오면 개행 해준다음 길이 0으로 초기화.
            cout << '\n';
            str_length = 0;
        } else if (v[i] == "<hr>") {
            if (str_length == 0) {
                for (int j = 0; j < 10; j++) {
                    cout << "--------";
                }
                cout << '\n';
                str_length = 0;
            } else {
                cout << '\n';
                for (int j = 0; j < 10; j++) {
                    cout << "--------";
                }
                cout << '\n';
                str_length = 0;
            }
        } else {// 태그가 아닌 다른 단어들
            if (str_length + v[i].size() < 80) {// 문장이 80개를 안넘었다면
                if (str_length == 0) {// str 길이가 0이면,
                    cout << v[i];
                    str_length += v[i].size();
                } else {
                    cout << ' ' << v[i];
                    str_length += v[i].size() + 1;
                }

            } else {// 문장이 80개 넘었다면 개행
                cout << '\n' << v[i];
                str_length = v[i].size();
            }
        }
    }
}
