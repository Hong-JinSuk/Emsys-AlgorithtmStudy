#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <stack>
#define MAX 1000001

using namespace std;
using lld = long long;
using info = pair<int, int>;
using dvect = vector<vector<int>>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	lld ans;
	cin >> n;
	ans = n;
	for (int i = 1; i <= sqrt(n); i++) {
		ans += max(0, (n - 1) / i - (int)sqrt(n));
	}
	for (int i = 1; i <= sqrt(n); i++) {
		ans += (n - 1) / i;
	}
	cout << ans;

	return 0;
}
