#include<iostream>
#include<vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, h, downc = 0, upc = 0, min, temp, count = 0;
	cin >> n >> h;
	min = n;
	upc = n / 2;
	vector<int> up(h+1, 0);
	vector<int> down(h+1, 0);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (i % 2) {
			up[temp]++;
		}
		else {
			down[temp]++;
		}
	}

	for (int i = 0; i < h; i++) {
		upc -= up[i];
		downc += down[h - i];
		temp = upc + downc;
		if (min > temp) {
			min = temp;
			count = 1;
		}
		else if (min == temp)
			count++;
	}

	cout << min << " " << count;
}