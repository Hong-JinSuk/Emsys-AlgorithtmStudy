#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#define MAX 2000000001

using namespace std;
using lld = long long;

vector<int>arr;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n,i,j,mini=MAX,ansA,ansB;
    cin >> n; arr.resize(n); i = 0, j = n - 1;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    while (i < j) {
        if (abs(arr[i] + arr[j]) < mini) {
            mini = abs(arr[i] + arr[j]);
            ansA = arr[i];
            ansB = arr[j];
        }
        if (abs(arr[i]) > abs(arr[j]))i++;
        else j--;
    }

    cout << ansA << ' ' << ansB;

    return 0;
}
