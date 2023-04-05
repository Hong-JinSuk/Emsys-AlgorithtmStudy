#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, left_time;

bool compare(pair<int, int> p, pair<int, int> p2) {
    if (p.second == p2.second) return p.first < p2.first;
    return p.second > p2.second;
}

int main() {
    cin >> n >> left_time;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    int result=0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first>left_time) continue;
        else {
            left_time = left_time-v[i].first;
            result+=v[i].second;
        }
        if(left_time<0) break;
    }
    cout<< result;
}
