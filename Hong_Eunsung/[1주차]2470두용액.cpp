#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, left = 0, right, min = 2000000000, minl = 0, minr, sumlr;
    cin >> n;
    right = n-1;
    minr = n-1;
    vector<int> yong(n);
    for(int i = 0; i < n; i++){
        cin >> yong[i];
    }
    sort(yong.begin(), yong.end());
    while(left < right){
        sumlr = yong[left] + yong[right];
        if(abs(sumlr) < min){
            min = abs(sumlr);
            minl = left;
            minr = right;
        }
        if(sumlr == 0){
            minl = left;
            minr = right;
            break;
        }
        else if(sumlr < 0){
            left++;
        }
        else{
            right--;
        }
    }
    cout << yong[minl] << " " << yong[minr];
}
