#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

string dict[MAX];
string temp[MAX];
string key;
int n;

void merge(int l, int r) {
	int mid = (l + r) / 2;
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (dict[i].length() < dict[j].length()) temp[k++] = dict[i++];
		else temp[k++] = dict[j++];
	}
	while (i <= mid) temp[k++] = dict[i++];
	while (j <= r) temp[k++] = dict[j++];
	for (i = l; i <= r; i++) dict[i] = temp[i];
}

void partition(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	partition(l, mid);
	partition(mid + 1, r);
	merge(l, r);
}

void sol() {
	queue<string>comp;
	string ans;
	comp.push(key);
	int s = comp.size(), last = 0;
	while (dict[last++] != key);
	while (s) {
		queue<string>t;
		ans = comp.front();
		while (!comp.empty()) {
			int cup = last;
			string k = comp.front();
			while (dict[cup].length() <= k.length())cup++;
			last = cup;
			comp.pop();
			for (int i = cup-1; i<n; i++) {
				if (dict[i].length() <= k.length()) continue;
				if (dict[i].length() > k.length() + 1) {
					break;
				}
				int j = 0;
				for (auto p : dict[i]) {
					if (p == k[j])j++;
				}
				if (j >= k.length())t.push(dict[i]);
			}
		}
		swap(t, comp);
		s = comp.size();
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> key;
	for (int i = 0; i < n; i++) {
		cin >> dict[i];
	}
	partition(0, n-1);
	sol();
	
	return 0;
}
