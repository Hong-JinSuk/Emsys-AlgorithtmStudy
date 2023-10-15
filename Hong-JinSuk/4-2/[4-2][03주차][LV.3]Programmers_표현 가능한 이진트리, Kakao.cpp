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
// �θ� 0�϶�, �ڽ��� 1�� ��� isright=false�� �ǰ� ������.
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
        bitset<64> num(number); // 2^50 ���� �Է��̹Ƿ� 64�� ũ��� 2������ ���� 
        isright = true; // ǥ�� �������� Ȯ���ϴ� �Լ�
        string str = num.to_string();
        for (int i = 0; i < 64; i++) { // �ִ� ũ�⸸ŭ ����

            if (number < pow(2, i)) { // ������ ������ i�� ã�Ƴ� ex) 7�� i=3, 2^3
                for (int j = 0; j < 64; j++) { // ������ 2����(Ʈ��)�� ã�Ƴ�
                    if (i < pow(2, j)) {
                        // 42�� ��� 2^6 �̳��� ǥ���ȴ�.
                        // �׷���, Ʈ���� ������� 2^level - 1 �� ��带 �����Ƿ� j=7�̉�.
                        i = pow(2, j) - 1;
                        break;
                    }
                }
                // level�� ���� �߶���, �Ʒ� ��¹��� ���� �����ϱ� �����
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