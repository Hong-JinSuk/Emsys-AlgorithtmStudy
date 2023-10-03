#include<iostream>
#include<vector>
using namespace std;
typedef struct{
    int y;
    int x;
    int dir;
}robot;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a, b, n, m, t, k, newy, newx, crash1, crash2;//열크기,행크기,로봇개수,명령문개수,...
    char c;//명령어 문자 입력용 변수
    bool fail = false;//충돌하면 fail=true, 끝까지 충돌을 안 하면 fail=false
    cin >> a >> b >> n >> m;

    int map[102][102] = {0,};

    for(int i = 0; i <= a+1; i++){//아래위 벽생성
        map[0][i] = 101;
        map[b+1][i] = 101;
    }
    for(int i = 0; i <= b + 1; i++){//좌우 벽생성
        map[i][0] = 101;
        map[i][a+1] = 101;
    }

    vector<robot> r(n+1);//1~n번 로봇 배열 생성

    for(int i = 1; i <= n; i++){//1~n번 로봇 정보 입력
        cin >> r[i].x >> r[i].y >> c;
        if(c == 'S'){
            r[i].dir = 0;
        }
        else if(c == 'E'){
            r[i].dir = 1;
        }
        else if(c == 'N'){
            r[i].dir = 2;
        }
        else{
            r[i].dir = 3;
        }
        map[r[i].y][r[i].x] = i;
    }

    for(int i = 0; i < m; i++){
        cin >> t >> c >> k;
        if(fail){//이미 벽이나 로봇에 충돌할 경우 입력만 받고 시뮬레이션 없이 넘어간다.
            continue;
        }
        if(c == 'L'){
            r[t].dir = (r[t].dir + k) % 4;//k회 좌회전 수행
        }
        else if(c == 'R'){
            r[t].dir = (r[t].dir + 3 * k) % 4;//k회 우회전 수행
        }
        else{//F(전진)명령어일 경우
            for(int j = 0; j < k; j++){
                newy = r[t].y + dy[r[t].dir];
                newx = r[t].x + dx[r[t].dir];
                if(map[newy][newx]){
                    fail = true;
                    crash1 = t;
                    crash2 = map[newy][newx];
                    break;
                }
                else{//로봇위치수정, 맵반영
                    map[r[t].y][r[t].x] = 0;
                    map[newy][newx] = t;
                    r[t].y = newy;
                    r[t].x = newx;
                }
            }
        }
    }
    //시뮬레이션 최종결과 출력
    if(!fail){//충돌을 안 해서 fail == false인 경우
        cout << "OK";
    }
    else{
        if(crash2 == 101){//벽에 충돌한 경우
            cout << "Robot " << crash1<< " crashes into the wall";
        }
        else{//로봇에 충돌한 경우
            cout << "Robot " << crash1 << " crashes into robot " << crash2;
        }
    }
}
