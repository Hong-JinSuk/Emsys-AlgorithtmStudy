#include <cstdio>
#include <queue>
#include <algorithm>

typedef struct {
	int m;
	int n;
	int h;
} chk;

int tm[101][101][101],m,n,h;
bool decay();

std::queue<chk> tmt;

int main() {
    scanf("%d%d%d",&m,&n,&h);
    for(int hh=0;hh<h;hh++){
        for(int nn=0;nn<n;nn++){
            for(int mm=0;mm<m;mm++){
                scanf("%d",&tm[mm][nn][hh]);
                if(tm[mm][nn][hh]==1)
                    tmt.push({mm,nn,hh});
            }
        }
    }
    int i=0;
    while(decay()){
        i++;
    }
    for(int hh=0;hh<h;hh++){
        for(int nn=0;nn<n;nn++){
            for(int mm=0;mm<m;mm++){
                if(tm[mm][nn][hh]==0){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    printf("%d", i);
}

bool decay(){
    bool decayed=false;
    chk now;
    std::queue<chk> rotten;
    while(!tmt.empty()){
        now = tmt.front();
        tmt.pop();
        if(now.m<m-1&&tm[now.m+1][now.n][now.h]==0){
            tm[now.m+1][now.n][now.h]=1;
            rotten.push({now.m+1,now.n,now.h});
            decayed=true;
        }
        if(now.n<n-1&&tm[now.m][now.n+1][now.h]==0){
            tm[now.m][now.n+1][now.h]=1;
            rotten.push({now.m,now.n+1,now.h});
            decayed=true;
        }
        if(now.h<h-1&&tm[now.m][now.n][now.h+1]==0){
            tm[now.m][now.n][now.h+1]=1;
            rotten.push({now.m,now.n,now.h+1});
            decayed=true;
        }
        if(now.m>0&&tm[now.m-1][now.n][now.h]==0){
            tm[now.m-1][now.n][now.h]=1;
            rotten.push({now.m-1,now.n,now.h});
            decayed=true;
        }
        if(now.n>0&&tm[now.m][now.n-1][now.h]==0){
            tm[now.m][now.n-1][now.h]=1;
            rotten.push({now.m,now.n-1,now.h});
            decayed=true;
        }
        if(now.h>0&&tm[now.m][now.n][now.h-1]==0){
            tm[now.m][now.n][now.h-1]=1;
            rotten.push({now.m,now.n,now.h-1});
            decayed=true;
        }
    }
    swap(rotten,tmt);
    return decayed;
}
