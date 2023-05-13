#include<iostream>
#include<algorithm>
#include<cmath>
#define endl "\n"

using namespace std;

int n;
bool isSosu[5000002] = { false, };
bool Said[5000001] = { false, };

int d_large[3] = { 0,0,0 };
int g_large[3] = { 0,0,0 };

void Sosu_making() { // 에라토스 테네스의 체

	int s = 5000001;
	fill_n(isSosu, 5000001, true); // 전부 소수로 표시
	isSosu[0] = isSosu[1] = false; // 소수가 아닌 두 수 표시

	for (int i = 2; i <= sqrt(s); i++) { 
		if (isSosu[i] == true) {
			for (int j = i + i; j <= s; j += i) {
				isSosu[j] = false;
			}
		}
	}
}

void Game(int n, long long int& d_score, long long int& g_score) {
	int d_index = 0, g_index = 0;

	for (int i = 0; i < n; i++) {
		int dae, guu;
		cin >> dae >> guu; // 대웅이와 규성이가 순서대로 말함

		if (!isSosu[dae]) { // 대웅이가 말한게 소수가 아닌 경우
			if (g_large[2] == 0) { // 규성이가 말한 소수가 3개가 안되면
				g_score += 1000; // 천점을 더해준다.
			}
			else { // 규성이가 말한 소수가 3개 이상이라면
				g_score += g_large[0]; // 말한 소수 중 3번째로 큰 수를 더해준다.
			}
		}
		else if (Said[dae]) { // 대웅이가 말한게 이전에 말한 소수인 경우
			d_score -= 1000; // 해당팀 -1000
		}
		else { // 조건에 맞는 소수인 경우
			Said[dae] = true; // 말한 것으로 기록한다.
			if (d_index < 3) { // 대웅이가 말한 소수가 3개 미만이면
				d_large[d_index] = dae; // 말한 소수로 넣어주고 인덱스를 더한다.
				d_index++;
				if(d_index==3) sort(d_large, d_large + 3); // d_lareg[0] 가 3번째로 큰 수가 되게함.
			}
			else {
				d_large[0] = max(d_large[0], dae);
				sort(d_large, d_large + 3); // d_lareg[0] 가 3번째로 큰 수가 되게함.
			}
		}

		if (!isSosu[guu]) { 
			if (d_large[2] == 0) { 
				d_score += 1000; 
			}
			else { 
				d_score += d_large[0]; 
			}
		}
		else if (Said[guu]) {
			g_score -= 1000; 
		}
		else { 
			Said[guu] = true; 
			if (g_index < 3) { 
				g_large[g_index] = guu;
				g_index++;
				if (g_index == 3) sort(g_large, g_large + 3);
			}
			else {
				//cout << "guu say sosu!" << endl;
				g_large[0] = max(g_large[0], guu);
				sort(g_large, g_large + 3);
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	Sosu_making();

	cin >> n; // 라운드

	long long int d_score = 0, g_score = 0;
	Game(n, d_score, g_score);

	//cout << "대웅 : " << d_score << endl;
	//cout << "규성 : " << g_score << endl;

	if (d_score > g_score) cout << "소수의 신 갓대웅";
	else if (d_score < g_score) cout << "소수 마스터 갓규성";
	else cout << "우열을 가릴 수 없음";

	return 0;
}