#include <iostream>

using namespace std;

long long a, b;

long long sol(long long);

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> a >> b;

    cout << sol(b) - sol(a-1);
}

long long sol(long long k) {
    long long cnt = 0, i, r;
    if (!k) return 0;
    for (i = 1, r=0; i <= k/2; i *= 2, r++) {
        cnt = cnt * 2 + i;
    }
    return cnt+ (k - i)+sol(k-i)+1;
}
