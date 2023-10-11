#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct st {
    int y;
    int x;
    int punch;
    int dis;
};

int map[1000][1000];
bool visited[1000][1000][2];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs() {
    queue<st> que;
    st st1 = {0, 0, 0, 1};
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    que.push(st1);

    while (!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        int dis = que.front().dis;
        int punch = que.front().punch;
        que.pop();

        if (y == n - 1 && x == m - 1) return dis;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
                if (map[ny][nx] == 1 && punch == 0) {
                    visited[ny][nx][punch + 1] = true;
                    st1.x = nx;
                    st1.y = ny;
                    st1.dis = dis + 1;
                    st1.punch = punch + 1;
                    que.push(st1);
                } else if (map[ny][nx] == 0 && visited[ny][nx][punch]==false) {
                    visited[ny][nx][punch] = true;
                    st1.x = nx;
                    st1.y = ny;
                    st1.dis = dis + 1;
                    st1.punch = punch;
                    que.push(st1);
                }
                // map[ny][nx] == 1 && punch==1 이면 그냥 그냥 끝임.
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            map[i][j] = temp[j] - '0';
        }
    }
    int result = bfs();
    cout << result;
    return 0;
}
