#include <iostream>

using namespace std;

int main() {
	int k, s = 0;
	cin >> k;
	int i, imax;
	for (i = 1; i <= k; i++) {
		//s += (k / i) + ((k % i) ? 1 : 0);
		s += (k + (i - 1)) / i;
	}

	cout << s;
}
