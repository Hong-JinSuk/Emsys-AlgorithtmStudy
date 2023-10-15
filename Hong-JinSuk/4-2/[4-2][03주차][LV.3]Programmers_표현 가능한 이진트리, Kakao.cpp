#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;
//bool isright = true;
//string target;
//void check(int left, int right, bool havechild) {
//    int root = (left + right) / 2;
//    if (target[root] == '0') havechild = false;
//    if (!isright) return;
//    if (!havechild && target[root] == '1') {
//        isright = false;
//        return;
//    }
//    if (left != right) {
//        check(left, root - 1, havechild);
//        check(root + 1, right, havechild);
//    }
//    return;
//}
//
//vector<int> solution(vector<long long> numbers) {
//    vector<int> answer;
//
//    for (long long number : numbers) {
//        target = "";
//        int cnt = 0, level = 0;
//        isright = true;
//        while (1) {
//            if (number < (1 << cnt)) break;
//            cnt++;
//        }
//        while (1) {
//            if (cnt < (1 << level)) break;
//            level++;
//        }
//        for (long long i = 0; i < pow(2, level) - 1; i++) {
//            if (number % 2 == 0) target += "0";
//            else target += "1";
//            number /= 2;
//        }
//        int left = 0;
//        int right = pow(2, level) - 2;
//        bool havechild = true;
//        check(left, right, havechild);
//        if (isright) answer.push_back(1);
//        else answer.push_back(0);
//    }
//    return answer;
//}

string num_str;
bool isright = true;
// 부모가 0일때, 자식이 1인 경우 isright=false가 되게 설계함.
void check(int left, int right, bool havechild) {
    int root = (left + right) / 2;
    cout << left << " " << right << endl;
    if (num_str[root] == '0') havechild = false;
    if (!isright) return;
    if (!havechild && num_str[root] == '1') {
        isright = false;
        return;
    }
    if (left != right) {
        check(left, root - 1, havechild);
        check(root + 1, right, havechild);
    }
    return;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long number : numbers) {
        bitset<64> num(number); // 2^50 까지 입력이므로 64의 크기로 2진수를 만듬 
        isright = true; // 표현 가능한지 확인하는 함수
        string str = num.to_string();
        for (int i = 0; i < 64; i++) { // 최대 크기만큼 돌림

            if (number < pow(2, i)) { // 최적의 제곱수 i를 찾아냄 ex) 7은 i=3, 2^3
                for (int j = 0; j < 64; j++) { // 최적의 2진수(트리)를 찾아냄
                    if (i < pow(2, j)) {
                        // 42의 경우 2^6 이내로 표현된다.
                        // 그런데, 트리로 만들려면 2^level - 1 의 노드를 갖으므로 j=7이됌.
                        i = pow(2, j) - 1;
                        break;
                    }
                }
                // level에 따라서 잘라줌, 아래 출력문을 보면 이해하기 쉬울듯
                num_str = str.substr(64 - i, 64);
                cout << num_str << endl;
                break;
            }
        }

        int left = 0, right = num_str.size() - 1;
        bool havechild = true;
        check(left, right, havechild);
        if (isright) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}

int main() {

    vector<long long> numbers = { 7,42,5,423 };
    vector<int> answer = solution(numbers);
    for (int ans : answer)
        cout << ans << endl;
    return 0;
}