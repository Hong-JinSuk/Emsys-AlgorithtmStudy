#include <iostream>
using namespace std;
int hol[500001];
int zzak[500001];
int res = 2e8;
int cnt;
int main(){
    int N,H;
    cin>>N>>H;
    for(int i=0;i<N;i++){
        int h;
        cin>> h;
        if(i%2){// 홀일때 석순!
            hol[h]++;
        }
        else {//짝일때
            zzak[H-h+1]++; //H-h+1 을 하는이유는 종유석의 길이가 2라고 하면,실제로 닿는건 밑에서부터 2칸이기 때문에, 이렇게해줌.
        }
    }
    for(int i=H;i>0;i--){
        hol[i-1]+=hol[i];
    }
    for(int i=0;i<H;i++){
        zzak[i+1]+=zzak[i];
    }
    for(int i=0;i<H;i++){
        if(hol[i]+zzak[i]<res){
            res= hol[i]+zzak[i];
            cnt=1;
        }
        else if(hol[i]+zzak[i]==res) cnt++;
    }
    cout<<res<<' '<<cnt;
    return 0;
}
