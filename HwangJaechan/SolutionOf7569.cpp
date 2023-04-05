#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

struct place {
	int x, y, z;
}; // tomato의 위치를 기록할 데이터 타입 place 정의 

vector<place>tomato; //tomato의 위치를 저장할 array
bool visit[MAX][MAX][MAX];
int n, m, h,c;

void sol() {
	int dx[] = { -1,1,0,0,0,0 };
	int dy[] = { 0,0,-1,1,0,0 };
	int dz[] = { 0,0,0,0,-1,1 };
	while (1) {
		vector<place>temp; // tomato에 변화가 있는지 체크할 array
		for (auto i : tomato) {
			for (int j = 0; j < 6; j++) {
				int x = i.x + dx[j];
				int y = i.y + dy[j];
				int z = i.z + dz[j];
				if (x >= h || x < 0) continue;
				if (y >= m || y < 0) continue;
				if (z >= n || z < 0) continue;
				if (visit[x][y][z]) continue;
				visit[x][y][z] = 1;
				temp.push_back({ x,y,z });
			}
		}
		if (!temp.size()) return; // 만약 tomato에 변화가 없다면 sol()함수 종료 
		tomato.clear(); // tomato 정보 업데이트 
		for (auto i : temp) tomato.push_back(i);
		c++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				int a;
				cin >> a;
				if (a == 0)continue;
				if (a == 1) {
					tomato.push_back({ i,j,k }); // tomato의 위치 저장 
				}
				visit[i][j][k] = 1; // 벽이라면 visit처리를 하여 업데이트에 방해를 하지 않도록 함. 
			}
		}
	}

	sol();
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (!visit[i][j][k]) { // 만약 익지 않은 토마토가 존재한다면 -1 출력후 종료 
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << c; // 익지 않은 토마토가 없으므로 c출력 후 종료

	return 0;
}
