#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << "0";
		return 0;
	}
	int i = 1, diff = y - x, day = 0;
	for (; "solve";i++) {
		diff -= i;
		day++;
		if (diff <= 0) {
			break;
		}
		diff -= i;
		day++;
		if (diff <= 0) {
			break;
		}
	}
	cout << day;
}
