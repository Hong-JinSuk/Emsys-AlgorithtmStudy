#include <algorithm>
#include <iostream>

using namespace std;

int s[100000];       // 각 idx 마다 석순의 크기저장. -> sort 로 정렬할거임.
int z[100000];       // 각 idx 마다 종유석의 크기저장. -> sort 로 정렬할거임.
int s_high[500001];  // s_high의 idx 는 동굴의 높이를 의미. 높이마다 석순을 지나는 횟수를 입력.
int z_high[500001];  // z_high의 idx 는 동굴의 높이를 의미. 높이마다 석순을 지나는 횟수를 입력.
int total[500001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, h;
    cin >> n >> h;
    int i, j;

    for (i = 0; i < n; i++) {
        if (i % 2==0) {  // i == 0 이나 짝수일때 는 석순의 크기입력.
            cin >> s[i / 2];
        } else {  // i == 홀수 일때는 종유석의 크기입력.
            cin >> z[i / 2];
        }
    }
    //for(i=0;i<n;i++) cout<< z[i]<<' ';
    if (n % 2) {  // 길이가 홀수이면, 석순이 n/2보다 하나많기때문에, sort 범위를 하나더해줌
        sort(s, s + n / 2 + 1);
    } else {  // 길이가 짝수이면, 석순이 n/2 개이므로 sort 범위는 종유석과 같다.
        sort(s, s + n / 2);
    }
    sort(z, z + n / 2);  // 종유석의 sort범위는 항상 n/2 이다.

    if (n % 2)
        n = n / 2 + 1;
    else
        n = n / 2;

    //for(i=0;i<n;i++) cout<< z[i]<<' ';

    for (i = n-1; i >= 0; i--) {
        if (s[i] > s[i + 1])
            s_high[s[i]] = 1;  // s[i]가 마지막 원소 이기때문에 첫시작을 1로 잡음.
        else if (s[i] < s[i + 1])
            s_high[s[i]] = s_high[s[i + 1]] + 1;  // 높이가 작은 값으로 내려가면, 높이가 큰 값의 지나는 수를 물려받고 1 더해줌.
        else
            s_high[s[i]]++;  // 원소가 중복해서 나오면 하나더해줌.

        if (z[i] > z[i + 1])
            z_high[h - z[i] + 1] = 1;
        else if (z[i] < z[i + 1])
            z_high[h - z[i] + 1] = z_high[h - z[i + 1] + 1]+1;
        else
            z_high[h - z[i] + 1]++;
    }
    //for(i=1;i<=h;i++) cout<< z_high[i]<<' ';
    for(i=h-1;i>0;i--){
        if(s_high[i]==0)s_high[i] = s_high[i+1];
    }
    for(i=1;i<=h;i++){
        if(z_high[i+1]==0)z_high[i+1] = z_high[i];
    }

    //for(i=1;i<=h;i++) cout<< z_high[i]<<' ';

    int minimum = 2e8;
    int cnt = 0;

    for (int i = 1; i <= h; i++) {
        total[i] = s_high[i] + z_high[i];
        if (minimum > total[i]) {
            minimum = total[i];
            cnt = 1;
        } else if (total[i] == minimum) {
            cnt++;
        }
    }
    cout << minimum<<' ' << cnt;
}
