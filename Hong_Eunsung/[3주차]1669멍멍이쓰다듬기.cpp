#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int dif, x, y, i = 0;
    cin >> x >> y;
    dif = y - x;

    while(dif >= 0){
        dif -= (i+1)/2;
        if(dif <= 0){
            cout << i;
            break;
        }
        i++;
    }
}
