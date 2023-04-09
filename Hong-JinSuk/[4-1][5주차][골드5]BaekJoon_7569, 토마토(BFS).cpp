#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#define endl "\n"
using namespace std;

int m, n, h, cnt;
int arr[101][101][101]; //가로,세로,높이
vector<tuple<int, int, int>> Start;
queue<tuple<int,int,int>> q;
// 오른쪽, 왼쪽, 위로, 아래, 윗층, 아랫츠
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
		// 하룻동안 모든 토마토가 이웃하는 토마토를 익게한다.
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
				// 다음 지점이 정해진 블럭을 넘어가지 않는다면
				if (next_x > -1 && next_x < m && next_y > -1 && next_y < n && next_z > -1 && next_z < h) {
					// 다음 지점에 토마토가 있고, 덜 익은 토마토라면
					if (arr[next_x][next_y][next_z] != -1 && arr[next_x][next_y][next_z] == 0) {
						q.push({ next_x,next_y,next_z }); // 다음 지점으로 넣어주고
						arr[next_x][next_y][next_z] = 1; // 익은걸로 표시해준다.
					}
				}
			}
		}
		cnt++; // 하루를 추가해준다.
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