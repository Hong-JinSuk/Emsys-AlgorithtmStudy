#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector <int> time;
vector <int> score;
int dp[101][10001];


int main(void) {
    cin >> n >> m;
    int t, s;

    time.push_back(0);
    score.push_back(0);
    for(int i=1; i<=n; i++) {
        cin >> t >> s;
        time.push_back(t);
        score.push_back(s);
    }

    for(int i=1; i<=n; i++) {   //i단원
        for(int j=1; j<=m; j++) {   //j분
            
            if(time[i] <= j){   //시간이 j분안에 들어가면
                // 남은시간까지의 스코어와 i단원 스코어를 얻은값과 이전값중에 큰값넣기
                dp[i][j] = max(score[i]+dp[i-1][j-time[i]], dp[i-1][j]);
            }else {
                //안들어가면위에거가져옴.
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][m];

    return 0;
}
