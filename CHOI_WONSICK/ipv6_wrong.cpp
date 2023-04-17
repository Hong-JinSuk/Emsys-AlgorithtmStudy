#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> vec;

int main() {
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ':') cnt++;
    }
    string temp;
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ':') {  // : 일경우
            if (temp.size() == 0 && str[i + 1] == ':') {
                for (int j = 0; j < 8 - cnt; j++) {
                    vec.push_back("0000:");
                }
                continue;
            } else {
                int s = temp.size();
                for (int j = 0; j < 4 - s; j++) {
                    temp.insert(0, "0");
                }
                temp += ":";
                vec.push_back(temp);
                temp = "";
            }
        } else {  // 숫자일경우
            temp += str[i];
            if (i == str.size() - 1) {
                int s = temp.size();
                for (int j = 0; j < 4 - s; j++) {
                    temp.insert(0, "0");
                }
                vec.push_back(temp);
            }
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        if (i == 7) {
            for (int j = 0; j < 4; j++) {
                cout << vec[i][j];
            }
        } else
            cout << vec[i];
    }
}
