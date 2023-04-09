#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#define endl "\n"
using namespace std;

int m, n, h, cnt;
int arr[101][101][101]; //����,����,����
vector<tuple<int, int, int>> Start;
queue<tuple<int,int,int>> q;
// ������, ����, ����, �Ʒ�, ����, �Ʒ���
int nx[6] = { 1,-1,0,0,0,0 };
int ny[6] = { 0,0,1,-1,0,0 };
int nz[6] = { 0,0,0,0,1,-1 };
void BFS() {
	int x, y, z;

	for (int i = 0; i < Start.size(); i++) {
		x = get<0>(Start[i]);
		y = get<1>(Start[i]);
		z = get<2>(Start[i]);
		q.push({ x,y,z });
	}

	while (!q.empty()) {
		// �Ϸ��� ��� �丶�䰡 �̿��ϴ� �丶�並 �Ͱ��Ѵ�.
		int Size = q.size();
		for (int i = 0; i < Size; i++) {
			x = get<0>(q.front());
			y = get<1>(q.front());
			z = get<2>(q.front());
			q.pop();
			//cout << "x,y,z : " << x << ", " << y << ", " << z << endl;
			for (int i = 0; i < 6; i++) {
				int next_x = x + nx[i];
				int next_y = y + ny[i];
				int next_z = z + nz[i];
				// ���� ������ ������ ���� �Ѿ�� �ʴ´ٸ�
				if (next_x > -1 && next_x < m && next_y > -1 && next_y < n && next_z > -1 && next_z < h) {
					// ���� ������ �丶�䰡 �ְ�, �� ���� �丶����
					if (arr[next_x][next_y][next_z] != -1 && arr[next_x][next_y][next_z] == 0) {
						q.push({ next_x,next_y,next_z }); // ���� �������� �־��ְ�
						arr[next_x][next_y][next_z] = 1; // �����ɷ� ǥ�����ش�.
					}
				}
			}
		}
		cnt++; // �Ϸ縦 �߰����ش�.
	}

}

int main() {

	cin >> m >> n >> h;

	bool isFinish = true;

	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> arr[x][y][z];
				if (arr[x][y][z] == 0) isFinish = false;
				if (arr[x][y][z] == 1) Start.push_back({ x,y,z });
			}	
		}
	}

	if (isFinish) {
		cout << 0;
		return 0;
	}

	BFS();

	/*for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cout << arr[k][j][i];
			}
			cout << endl;
		}
		cout << endl;
	}*/

	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (arr[x][y][z] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << --cnt;

	return 0;
}