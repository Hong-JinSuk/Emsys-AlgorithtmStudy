#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
풀이전략
: 이중bfs를 구현한다. 1,1에서 출발하여 거리를 구하는 bfs와, n,m에서 출발하여 거리를 구하는 bfs.
맵의 주위 2칸은 벽을 세워둔다. map에 이동할 수 없는 길이 1이므로 여긴 전부 1.
이중 for문을 돌면서 탐색한다. s2d[i][j]와 d2s[i+dy][j+dx]의 값을 합한 뒤 2를 더하여 newdist를 만들고 이를 min과 비교하여 갱신한다. 
*/

//주의할 점 : 아예 막혀있는 경우는 min을 초기화할 때 주의해야 한다.
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ddy[8] = {-2, 0, 2, 0, -1, -1, 1, 1};
int ddx[8] = {0, 2, 0, -2, -1, 1, -1, 1};

struct p{
    int y;
    int x;
};

queue<p> bfsQ;

void bfs(vector<vector<int>> map, vector<vector<int>> &a){//map은 visit표시를 위해 0->1로 값이 수정되므로 call by value, a는 s2d와 d2s라서 reference.
    int size, nowy, nowx, newy, newx, dist = 1;
    while(!bfsQ.empty()){
        size = bfsQ.size();
        dist++;
        for(int i = 0; i < size; i++){
            nowy = bfsQ.front().y;
            nowx = bfsQ.front().x;
            map[nowy][nowx] = 1;
            for(int j = 0; j < 4; j++){//dy, dx 적용
                newy = nowy + dy[j];
                newx = nowx + dx[j];
                //만약 new좌표에 길이 있으면(방문하지 않았으면) 방문표시하고 dist를 a에 기록한 뒤 큐에 삽입한다.
                if(!map[newy][newx]){
                    map[newy][newx] = true;
                    a[newy][newx] = dist;
                    bfsQ.push({newy, newx});
                }
            }
            bfsQ.pop();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, min = INT_MAX, ny, nx, nd;
    string s;
    cin >> n >> m;
    vector<vector<int>> map(n+4, vector<int>(m+4, 1));//지도가 표시될 이차원배열
    vector<vector<int>> s2d(n+4, vector<int>(m+4, 1000000000));//map의 start point(0,0)부터 시작해 destination(n,m)쪽으로 bfs해나가며 거리를 저장할 이차원 배열
    vector<vector<int>> d2s(n+4, vector<int>(m+4, 1000000000));//반대로 (n,m)에서 (0,0)을 향해 bfs해나갈 dest to start 이차원배열
    //벽만들기
    for(int i = 0; i <= m+3; i++){//가로 벽 만들기. 위 2층 아래 2층
        map[0][i] = 1;
        map[1][i] = 1;
        map[n+2][i] = 1;
        map[n+3][i] = 1;
    }
    for(int i = 0; i <= n+3; i++){//세로 벽 만들기. 좌 2줄 우 2줄
        map[i][0] = 1;
        map[i][1] = 1;
        map[i][m+2] = 1;
        map[i][m+3] = 1;
    }

    for(int i = 2; i <= n+1; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            map[i][j+2] = (int)(s[j] - '0');
        }
    }


    bfsQ.push({2,2});//s2d bfs를 위한 시작 지점 설정.
    s2d[2][2] = 1;
    bfs(map, s2d);//bfs하며 s2d에 distance갱신
    if(s2d[n+1][m+1] != 1000000000){
        min = s2d[n+1][m+1];
    }

    bfsQ = queue<p>();
    bfsQ.push({n+1, m+1});//d2s bfs를 위한 시작 지점 설정.
    d2s[n+1][m+1] = 1;
    bfs(map, d2s);//bfs하며 d2s에 distance 갱신

    //이중for문 루프하며 최소경로 갱신
    for(int i = 2; i <= n+1; i++){
        for(int j = 2; j <= m+1; j++){
            if(s2d[i][j] >= 1000000000){
                continue;
            }
            for(int k = 0; k < 8; k++){
                ny = i+ddy[k];
                nx = j+ddx[k];
                nd = s2d[i][j] + d2s[ny][nx] + 1;
                if(!map[ny][nx] && nd < min) {//길이 있고, 합이 최솟값보다 작으면
                    min = nd;
                }
            }
        }
    }

    //길이 없는 경우 -1, 있으면 최단경로 길이 출력
    if(min >= 1000000000){
        cout << -1 << "\n";
    }
    else{
        cout << min;
    }
}
