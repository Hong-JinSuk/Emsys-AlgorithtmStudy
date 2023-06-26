#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long arr[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, ans = 1000001;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
	int i = 0, j = 0;
	while (i <= n && j <= n) {
		if (arr[j] - arr[i] < m)j++;
		else {
			ans = min(ans, j - i);
			i++;
		}
	}

	if (ans == 1000001)cout << 0 << '\n';
	else cout << ans << '\n';

	return 0;
}
