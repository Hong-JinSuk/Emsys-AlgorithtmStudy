#include <string>
#include <vector>
#include <iostream>

using namespace std;

int mini;

void checkit(long long node, long long weight, bool before, string& s) {
    bool now = s[node - 1] - '0';
    if (node < 0 || node > s.length()) return;
    if (weight == 0) {
        if (s[node - 1]-'0' == 1 && before == 0) {
            mini = 0;
            return;
        }
        else return;
    }
    if (now == 1 && before == 0) {
        mini = 0;
        return;
    }
    else {
        checkit(node - weight, weight / 2, now, s);
        checkit(node + weight, weight / 2, now, s);
        return;
    }
}

bool judge(long long k) {
    string str = "";
    long long t = 1;
    while (t <= k)t *= 2;
    t /= 2;
    while (t >= 1) {
        if (k >= t) {
            str += "1";
            k -= t;
        }
        else {
            str += "0";
        }
        t /= 2;
    }
    long long x = 2;
    while (x - 1 < str.length())x *= 2;
    string xx = "";
    while (xx.length() + str.length() < x - 1)xx += "0";
    str = xx + str;
    cout << str << '\n';
    mini = 1;
    checkit(x / 2, x / 4, 1, str);
    return mini;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (auto i : numbers) {
        answer.push_back(judge(i));
    }

    return answer;
}
