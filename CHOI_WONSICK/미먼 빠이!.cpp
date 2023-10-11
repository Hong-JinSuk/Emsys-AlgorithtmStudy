#include<iostream>
#include<queue>

using namespace std;
struct Point {
    int x;
    int y;
};

int map[51][51];
int temp[51][51];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int n, m, t;
Point air_cleaner[2];
int a_c_p;
queue<Point> que;

void search() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0) {
                que.push({j, i});
            }
            temp[i][j] = map[i][j];
        }
    }
}

void bfs() {
    while (!que.empty()) {
        Point cur = que.front();
        que.pop();
        int cnt = 0;
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if (map[ny][nx] == -1) {
                continue;
            }
            temp[ny][nx] += (map[cur.y][cur.x] / 5);
            cnt++;
        }
        temp[cur.y][cur.x] -= (map[cur.y][cur.x] / 5) * cnt;
    }
}

void air_cleaner_func() {
    auto a = air_cleaner[0];
    auto b = air_cleaner[1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 윗부분.
            if (i <= a.y) {
                if (temp[i][j] == -1) {
                    map[i][j + 1] = 0;
                }
                if (a.y == i && a.x < j && j < m - 1) {// 우
                    map[i][j + 1] = temp[i][j];
                } else if (a.y >= i && i > 0 && j == m - 1) {// 상
                    map[i - 1][j] = temp[i][j];
                } else if (i == 0 && a.x < j) {// 좌
                    map[i][j - 1] = temp[i][j];
                } else if (j == 0 && a.y > i) {// 하
                    if (i == a.y - 1 && j == a.x) {
                        continue;
                    } else map[i + 1][j] = temp[i][j];
                } else {
                    map[i][j] = temp[i][j];
                }
            } else {
                // 아랫부분
                if (temp[i][j] == -1) {
                    map[i][j + 1] = 0;
                }
                if (b.y == i && b.x < j && j < m - 1) {//우
                    map[i][j + 1] = temp[i][j];
                } else if (b.y <= i && i < n - 1 && j == m - 1) {//하
                    map[i + 1][j] = temp[i][j];
                } else if (i == n - 1 && b.x < j) {//좌
                    map[i][j - 1] = temp[i][j];
                } else if (j == 0 && b.y < i) {//상
                    if (i == b.y + 1 && j == b.x) {
                        continue;
                    }
                    map[i - 1][j] = temp[i][j];
                } else {
                    map[i][j] = temp[i][j];
                }
            }
        }
    }
}

int main() {
    int result = 0;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            temp[i][j] = map[i][j];
            if (map[i][j] == -1) {
                air_cleaner[a_c_p++] = {j, i};
            }
        }
    }
    while (t--) {
        search();
        bfs();

        air_cleaner_func();
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << temp[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0) {
                result += map[i][j];
            }
//            cout << map[i][j] << ' ';
        }
//        cout << '\n';
    }
    cout << result;
}
