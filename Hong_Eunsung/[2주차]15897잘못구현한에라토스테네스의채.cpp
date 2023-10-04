#include<iostream>
#include<math.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long sum = 0;
    int n, i, j, mid;

    cin >> n;
    n--;

    mid = sqrt(n); //이거랑 아래 for문은 최적화를 위해 넣은 것. 없어도 문제 자체는 0ms에 통과하지만 있으면 i <= sqrt(n)일 때 불필요한 연산이 줄어든다.
    for(i = 1; i <= mid; i++){
        sum += (n/i);
    }
    
    for(i = mid+1; i <= n; i = j+1){//위의 최적화 for문을 넣지 않으면 i=1로 초기한다.
        j = n/(n/i);
        sum += (n/i)*(j-i+1);
    }
    sum += n+1;

    cout << sum;
}
