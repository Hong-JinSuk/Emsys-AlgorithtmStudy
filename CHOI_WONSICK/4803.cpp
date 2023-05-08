#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[501];
int visited[501];

bool dfs(int x, int post_x) {
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        if (graph[x][i] == post_x) continue;
        if (visited[graph[x][i]]) return false;
        if (dfs(graph[x][i], x) == false) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n, m;
    int t = 0;
    while (1) {
        t++;
        int cnt = 0;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        for (int i = 1; i <= 500; i++) {
            graph[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (dfs(i, 0)) cnt++;
            }
        }

        cout << "Case " << t << ": ";
        if (cnt > 1)
            cout << "A forest of " << cnt << " trees." << endl;
        else if (cnt == 1)
            cout << "There is one tree." << endl;
        else
            cout << "No trees." << endl;
    }
}
