#include <iostream>
#include <utility>

using namespace std;
using the_thing = pair<int, int>; // weight,value 

int cupbag[100001];
int resultbag[100001];
the_thing things[100];

void solution(int n, int maxweight) {
	for (int i = 0; i < n; i++) {
		for (int j = things[i].first; j <= maxweight; j++) {
			resultbag[j] = max(cupbag[j], things[i].second + cupbag[j - things[i].first]);
		}
		for (int j = 1; j <= maxweight; j++) {
			cupbag[j] = resultbag[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k; // input
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> things[i].first >> things[i].second;
	}

	solution(n, k);

	cout << resultbag[k];

	return 0;
}
