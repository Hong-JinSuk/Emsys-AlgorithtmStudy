#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> arr(1000001);

int find(int a){ //union-find의 find함수
    if(arr[a].first == a){
        return a;
    }
    else{
        return arr[a].first = find(arr[a].first);
    }
}

void merge(int a, int b){//union-find의 union함수
    int x = find(a), y = find(b);
    if(x==y){
        return;
    }
    arr[x].first = arr[y].first;
    arr[y].second += arr[x].second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i <= 1000000; i++){
        arr[i].first = i;
        arr[i].second = 1;
    }

    int n, p, q;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'I'){
            cin >> p >> q;
            merge(p, q);
        }
        else{
            cin >> p;
            cout << arr[find(p)].second << "\n";
        }
    }
}
