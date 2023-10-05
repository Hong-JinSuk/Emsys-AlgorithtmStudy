#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int r1, r2, c1, c2, max = 0, c, maxNum = 0, now, psize = 0;

    cin >> r1 >> c1 >> r2 >> c2;
    vector<vector<int>> map((r2-r1+1), vector<int>(c2-c1+1, 0));

    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            max = abs(i)>=abs(j)?abs(i):abs(j);
            if(max == i){
                now = (2*max + 1)*(2*max+1) - max + j;
                map[i-r1][j-c1] = now;
                if(now > maxNum){
                    maxNum = now;
                }
            }
            else if(max == -i){
                now = (2*max + 1) * ( 2*max+1) - 5*max - j;
                map[i-r1][j-c1] = now;
                if(now > maxNum){
                    maxNum = now;
                }
            }
            else if(max == j){
                now = (2*max-1)*(2*max-1) + max - i;
                map[i-r1][j-c1] = now;
                if(now > maxNum){
                    maxNum = now;
                }
            }
            else{
                now = (2*max-1)*(2*max-1) - 5*j + i;
                map[i-r1][j-c1] = now;
                if(now > maxNum){
                    maxNum = now;
                }
            }
        }
    }

    while(maxNum>0){
        maxNum /= 10;
        psize++;
    }

    cout.width(psize);

    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            cout.width(psize);
            cout << map[i-r1][j-c1] << " ";
        }
        cout << "\n";
    }

}
