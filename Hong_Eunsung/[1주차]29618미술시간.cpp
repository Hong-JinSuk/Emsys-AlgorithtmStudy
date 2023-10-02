#include<iostream>
#include<vector>
using namespace std;

int p[100002] = {0,};
int c[100002] = {0,};

int find(int a){
    if(p[a] != a){
        return p[a] = find(p[a]);
    }
    else if(c[a+1]){
        p[a+1] = find(p[a+1]);
        return p[a] = p[a+1];
    }
    else{
        return a;
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, q, a, b, x, y;
    cin >> n >> q;
    for(int i = 0; i <= n+1; i++){
        p[i] = i;
    }

    for(int i = 0; i < q; i++){
        cin >> a >> b >> x;
        y = find(b);
        for(int j = a; j <= b; j++){
            if(c[j]){
                j = find(p[j]);
                continue;
            }
            c[j] = x;
            p[j] = y;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << c[i] << " ";
    }
}
