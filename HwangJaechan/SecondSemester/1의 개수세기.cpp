#include <iostream>
#include <vector>

using namespace std;
using lld = long long;

lld counting(lld k) { // k까지의 1의 개수 세는 함수 
	if (k <= 0)return 0;
	lld o = k;
	lld tmp = 1,cnt = 0;
	while (k >= tmp) {
		cnt += (o / (tmp*2))*tmp;
		lld other = o % (tmp*2);
		cnt += min(other, tmp);

		tmp *= 2;
		o = k - tmp+1;
	}

	return cnt;
}

int main() {
	lld left,right;
	cin >> left >> right;/
	cout << counting(right) - counting(left - 1);//출력

	return 0;
}
