#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int dp[101][10001];
int main() {
    int n, time_;
    vector<pair<int, int> > v;
    cin >> n >> time_;
    for (int i = 0; i < n; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= time_; j++) {
            int curTime = v[i - 1].first;
            int curPoint = v[i - 1].second;

            if (curTime <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curTime] + curPoint);
            } else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][time_];
    return 0;
}
//냅색 알고리즘사용
