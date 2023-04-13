#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

queue<string> a[81], ok;
char start[81];
char gyarados[81];

void vurp();
bool able(const char*, const char*);

int main() {
    string g = "입력용 임시변수";
    int d, nlen;
    scanf("%d%s", &d, start);
    nlen = strlen(start);
    strcpy(gyarados,start);
    for(int i=0; i<d; i++){
        cin>>g;
        a[g.length()].push(g);
    }
    queue<string> tmp;
    swap(ok, tmp);
    g = start;
    ok.push(g);
    vurp();
    printf("%s", gyarados);
}

void vurp(){
    while(!ok.empty()){
        int l = ok.front().length(), k = a[l+1].size();
        for(int i=0; i<k; i++){
            if(able(ok.front().c_str(), a[l+1].front().c_str())){
                ok.push(a[l+1].front());
            }else{
                a[l+1].push(a[l+1].front());
            }
            a[l+1].pop();
        }
        strcpy(gyarados, ok.front().c_str());
        ok.pop();
    }
    return;
}

bool able(const char *st, const char *nd){
    int l = strlen(nd), chance = 0;
    for(int i=0; i<l; i++){
        if(st[i-chance]!=nd[i]){
            if(!chance){
                chance = 1;
            }
            else{
                return false;
            }
        }
    }
    return true;
}
