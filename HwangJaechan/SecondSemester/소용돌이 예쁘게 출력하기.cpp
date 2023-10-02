#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define MAX 1000001

using namespace std;
using lld = long long;
using info = pair<pair<int,int>, int>;
using dvect = vector<vector<bool>>;

vector<int> arr;
int ans[50][5];

int calPosi(int y, int x) {
	if (x == 0 && y == 0) return 1;
	int outside = max(abs(y), abs(x));
	if (y == outside || x == outside * -1) {
		return arr[outside] - abs(outside - y) - abs(outside - x);
	}
	else {
		return arr[outside-1] + abs(outside - y) + abs(outside - x);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int sy, sx, ex, ey;
	cin >>sy >> sx >> ey >> ex;
	int maxi = max(max(abs(sx), abs(sy)), max(abs(ex),abs(ey)));
	int biggest = 0;
	arr.resize(maxi+1);
	for (int i = 0; i <= maxi; i++) {
		arr[i] = (i * 2 + 1) * (i * 2 + 1);
	}
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			ans[i-sy][j-sx] =  calPosi(i, j);
			biggest = max(biggest, ans[i - sy][j - sx]);
		}
	}
	int l = 0;
	while (biggest > 0) {
		l++;
		biggest /= 10;
	}

	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			int tmp = ans[i - sy][j - sx];
			int ll = 0;
			while (tmp) {
				ll++;
				tmp /= 10;
			}
			for (int k = 0; k < l - ll; k++)cout << ' ';
			cout << ans[i - sy][j - sx] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
