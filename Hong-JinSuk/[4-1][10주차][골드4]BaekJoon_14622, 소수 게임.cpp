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

void Sosu_making() { // �����佺 �׳׽��� ü

	int s = 5000001;
	fill_n(isSosu, 5000001, true); // ���� �Ҽ��� ǥ��
	isSosu[0] = isSosu[1] = false; // �Ҽ��� �ƴ� �� �� ǥ��

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
		cin >> dae >> guu; // ����̿� �Լ��̰� ������� ����

		if (!isSosu[dae]) { // ����̰� ���Ѱ� �Ҽ��� �ƴ� ���
			if (g_large[2] == 0) { // �Լ��̰� ���� �Ҽ��� 3���� �ȵǸ�
				g_score += 1000; // õ���� �����ش�.
			}
			else { // �Լ��̰� ���� �Ҽ��� 3�� �̻��̶��
				g_score += g_large[0]; // ���� �Ҽ� �� 3��°�� ū ���� �����ش�.
			}
		}
		else if (Said[dae]) { // ����̰� ���Ѱ� ������ ���� �Ҽ��� ���
			d_score -= 1000; // �ش��� -1000
		}
		else { // ���ǿ� �´� �Ҽ��� ���
			Said[dae] = true; // ���� ������ ����Ѵ�.
			if (d_index < 3) { // ����̰� ���� �Ҽ��� 3�� �̸��̸�
				d_large[d_index] = dae; // ���� �Ҽ��� �־��ְ� �ε����� ���Ѵ�.
				d_index++;
				if(d_index==3) sort(d_large, d_large + 3); // d_lareg[0] �� 3��°�� ū ���� �ǰ���.
			}
			else {
				d_large[0] = max(d_large[0], dae);
				sort(d_large, d_large + 3); // d_lareg[0] �� 3��°�� ū ���� �ǰ���.
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

	cin >> n; // ����

	long long int d_score = 0, g_score = 0;
	Game(n, d_score, g_score);

	//cout << "��� : " << d_score << endl;
	//cout << "�Լ� : " << g_score << endl;

	if (d_score > g_score) cout << "�Ҽ��� �� �����";
	else if (d_score < g_score) cout << "�Ҽ� ������ ���Լ�";
	else cout << "�쿭�� ���� �� ����";

	return 0;
}