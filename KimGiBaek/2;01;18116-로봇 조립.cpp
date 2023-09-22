#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int robot[1001001], last, cnt[1001001];

void PartsLink(int,int);
void PrintPartsCount(int);
void PrintRobots();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i < 1000001; i++) {
        robot[i] = i;
        cnt[i] = 1;
    }
    
    int n, a, b;
    char i;
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> i;
        switch (i) {
        case 'I':
            cin >> a >> b;
            last = 10;
            PartsLink(a,b);
            //PrintRobots();
            break;
        case 'Q':
            cin >> a;
            PrintPartsCount(a);
            break;
        }
    }
}

void PartsLink(int parta, int partb) {
    int ahead, bhead;
    if (parta > partb) swap(parta, partb);
    vector<int> vv;
    ahead = parta;
    bhead = partb;
    while (ahead != robot[ahead]) {
        vv.push_back(robot[ahead]);
        ahead = robot[ahead];
    }
    while (bhead != robot[bhead]) {
        vv.push_back(robot[bhead]);
        bhead = robot[bhead];
    }
    int repeat = vv.size();
    if (ahead == bhead) {
        return;
    }
    else {
        cnt[ahead] += cnt[bhead];
        cnt[bhead] = 0;
        robot[parta] = robot[partb] = ahead;
        while (repeat--) {
            robot[vv.back()] = ahead;
        }
    }
    /*
    else if (ahead < bhead) {
        cnt[ahead] += cnt[bhead];
        cnt[bhead] = 0;
        robot[parta] = robot[partb] = ahead;
        while (repeat--) {
            robot[vv.back()] = ahead;
        }
    }
    else if (bhead < ahead) {
        cnt[bhead] += cnt[ahead];
        cnt[ahead] = 0;
        robot[parta] = robot[partb] = bhead;
        while (repeat--) {
            robot[vv.back()] = bhead;
        }
    }
    */
}

void PrintPartsCount(int partNum) {
    while (robot[partNum] != partNum) {
        partNum = robot[partNum];
    }
    //printf("%d\n", cnt[partNum]);
    cout << cnt[partNum] << "\n";
}

void PrintRobots() {
    for (int i = 1; i <= last; i++) {
        cout << robot[i] << " ";
    }
    cout << "\n";
}
