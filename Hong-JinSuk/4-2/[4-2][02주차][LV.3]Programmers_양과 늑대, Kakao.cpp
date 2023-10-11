#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> Road[18];
vector<int> Info;
bool isvisit[18];
bool Root[18];
int sheep = 0;
int wolf = 0;
int Answer = 0;
void dfs(int answer) {
    Answer = max(Answer, sheep);
    //cout << "answer : " << Answer << endl;
    for (int i = 0; i < Info.size(); i++) {
        if (isvisit[i]) { // 현재 방문한 지점 중에서
            for (auto end : Road[i]) { // 갈 수 있는 길들 조사
                if (!isvisit[end]) { // 아직 찾지 않은 놈들 중에서
                    if (Info[end] == 0) { // 양이면
                        sheep++;
                        answer++;
                        isvisit[end] = true;
                        dfs(answer); // 여기서 분기를 나누고 또 조사
                        sheep--;
                        answer--;
                        isvisit[end] = false;
                    }
                    else if (Info[end] == 1) { // 늑대면
                        wolf++;
                        isvisit[end] = true;
                        if (sheep > wolf) { // 양이 아직 더 많으면 분기를 나누고 조사
                            dfs(answer);
                        }
                        isvisit[end] = false;
                        wolf--;
                    }
                }
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    for (auto i : info)
        Info.push_back(i); // info 전역으로 복제

    for (auto x : edges) {
        Road[x[0]].push_back(x[1]); // start, end
        Root[x[1]] = false; // 루트로 가는 길은 없다.
    }

    int root = 0;
    for (int i = 0; i < info.size(); i++)
        if (Root[i]) root = i;

    isvisit[root] = true;
    sheep++;

    dfs(0);

    return Answer;
}

// 0 : 양, 1 : 늑대
int main() {

    vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
    vector<vector<int>> edges = { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} };

    cout << solution(info, edges);

    return 0;
}