#include <iostream>
#include <cstring>
#include <math.h>

bool chk[5000000], sosu[5000005];
int woong[3], gyu[3], schk=1;
long long ws,gs;

void rank(int h[3], int s);
void findSosu(int m);

int main() {
    int n, w, g;
    findSosu(5000002);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &w, &g);
        if(!sosu[w]){
            if(gyu[2])
                gs += gyu[2];
            else
                gs += 1000;
        }
        else if(!chk[w]){
            chk[w] = true;
            if(woong[2]<w){
                rank(woong, w);
            }
        }
        else{
            ws -= 1000;
        }
        if(!sosu[g]){
            if(woong[2])
                ws += woong[2];
            else
                ws += 1000;
        }
        else if(!chk[g]){
            chk[g] = true;
            if(gyu[2]<g){
                rank(gyu, g);
            }
        }
        else{
            gs -= 1000;
        }
    }
    if(ws>gs)
        printf("소수의 신 갓대웅");
    else if(ws<gs)
        printf("소수 마스터 갓규성");
    else
        printf("우열을 가릴 수 없음");
}

void rank(int h[3], int s){
    if(h[0]<s){
        h[2] = h[1];
        h[1] = h[0];
        h[0] = s;
    }
    else if(h[1]<s){
        h[2] = h[1];
        h[1] = s;
    }
    else if(h[2]<s)
        h[2] = s;
}
    //printf("%d",(int)sqrt(10));

void findSosu(int m){
    memset(sosu+2, true, sizeof(bool) * (m-2));
    for(int i=2; i<=sqrt(m); i++){
        if(sosu[i]){
            for(int j=i*2; j<=m; j+=i){
                sosu[j] = false;
            }
        }
    }
}
