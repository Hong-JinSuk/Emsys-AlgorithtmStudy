#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
    ll x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 0;
        return 0;
    }
    ll d = abs(y - x);
    ll rd = (ll) sqrt(d);
    ll dd = d - (ll) pow(rd, 2);
    ll cnt = rd * 2 - 1;
    cnt = cnt + (ll) ceil((double) dd / (double) rd);
    cout << cnt;
}
