#include <cstdio>
#include <queue>

void test();
int find(int a, int b, int tree[]);

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        test();
    }
}

void test(){
    int n, tree[10009]={0}, a, b, top;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        tree[b] = a;
    }
    scanf("%d %d", &a, &b);
    printf("%d\n", find(a,b,tree));
}

int find(int a, int b, int tree[]){
    int alvl, blvl, tmp, cnt;
    
    tmp = tree[a];
    cnt = 1;
    while(tmp){
        tmp = tree[tmp];
        cnt++;
    }
    alvl = cnt;

    tmp = tree[b];
    cnt = 1;
    while(tmp){
        tmp = tree[tmp];
        cnt++;
    }
    blvl = cnt;
    
    while(alvl>blvl){
        a = tree[a];
        alvl--;
    }
    while(alvl<blvl){
        b = tree[b];
        blvl--;
    }
    while(a!=b){
        a = tree[a];
        b = tree[b];
    }
    return a;
}
