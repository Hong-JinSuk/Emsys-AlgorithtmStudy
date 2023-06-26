#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];

int main(){
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int h=0,t=0;
    int sum=arr[0];
    int res=1e9;
    while(h<=t){
        if(sum<s){
            t++;
            sum+=arr[t];
        }
        else{
            res=min(t-h+1,res);
            sum-=arr[h];
            h++;
        }
        if(t>=n) break;
    }
    if(res==1e9)res =0;
    cout<<res;
}
