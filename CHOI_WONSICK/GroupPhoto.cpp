#include <string>
#include <vector>
using namespace std;
char mem[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
bool visited[8];
int answer;

void dfs(char arr[],int cnt, vector<string> data) {
    if (cnt == 8) {
        for (int i = 0; i < data.size(); i++) {
            char f1 = data[i][0];
            char f2 = data[i][2];
            char op = data[i][3];
            int dis = data[i][4]-'0';
            int f1_idx=-1;
            int f2_idx=-1;
            for(int j=0;j<8;j++){
                if(f1==arr[j]) f1_idx=j;
                if(f2==arr[j]) f2_idx=j;
            }
            if(op=='='&&abs(f1_idx-f2_idx)-1!=dis) return;
            if(op=='>'&&abs(f1_idx-f2_idx)-1<=dis) return;
            if(op=='<'&&abs(f1_idx-f2_idx)-1>=dis) return;
        }
        answer++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (visited[i] == true) continue;
        visited[i] = true;
        arr[cnt]=mem[i];
        dfs(arr,cnt + 1, data);
        visited[i] = false;
    }
}

int solution(int n, vector<string> data) {
    char arr[8]={NULL,};
    answer=0;
    dfs(arr,0,data);
    return answer;
}
