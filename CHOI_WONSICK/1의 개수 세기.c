#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
ll d[56];

void print_test(vector<int> &vec) {
    for (int i = 0; i <= 3; i++) {
        cout << vec[i] << '\n';
    }
}

void change_to_binary(vector<int> &vec, ll n) {// vec의 맨 마지막 idx가 msb 이다.
    while (n) {
        vec.push_back(n % 2);
        n /= 2;
    }
}

ll solve(vector<int> &vec, ll n) {
    ll res = 0;
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] == 1) {
            res += d[i - 1] + n - ((ll) 1 << i) + 1;
            n -= ((ll) 1 << i);
        }
    }
    return res;
}

int main() {
    ll n1, n2;
    cin >> n1 >> n2;
    d[0] = 1;

    for (int i = 1; i <= 55; i++) {
        d[i] = d[i - 1] * 2 + ((ll) 1 << i);
    }

    vector<int> vec1, vec2;
    change_to_binary(vec1, n1 - 1);
    change_to_binary(vec2, n2);
    ll sum_n1 = solve(vec1, n1 - 1);
    ll sum_n2 = solve(vec2, n2);
    cout << sum_n2 - sum_n1;
//    print_test(vec1);
}
