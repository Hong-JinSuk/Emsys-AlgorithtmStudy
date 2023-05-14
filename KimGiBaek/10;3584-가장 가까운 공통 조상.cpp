#include <cstdio>
#include <queue>

void test();
int find(int a, int b, int tree[], int level[]);

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        test();
    }
}

void test(){
    int n, tree[10009]={0}, a, b, top, level[10009]={0};
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        tree[b] = a;
    }
    scanf("%d %d", &a, &b);
    for(int i=1; i<=n; i++){
        if(tree[i]==0){
            top = tree[i];
            level[i] = 1;
        }
    }
    for(int i=2; ; i++){
        bool set = false;
        for(int j=1; j<=n; j++){
            if(level[tree[j]]==i-1){
                level[j] = i;
                set = true;
            }
        }
        if(!set)
            break;
    }
    printf("%d\n", find(a,b,tree,level));
}

int find(int a, int b, int tree[], int level[]){
    while(level[a]>level[b]){
        a = tree[a];
    }
    while(level[a]<level[b]){
        b = tree[b];
    }
    while(a!=b){
        a = tree[a];
        b = tree[b];
    }
    return a;
}
