#include <string>
#include <vector>
#include<set>
#include<map>
using namespace std;

struct user {
    int reportCount;
    set<int> reporter;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int comSize = report.size(), userSize = id_list.size(), mid, t1, t2, tempSize;
    answer = vector<int>(userSize, 0);
    map<string, int> userIndex;
    vector<user> userList;
    string a, b, temp;
    for (int i = 0; i < userSize; i++) {
        userIndex.insert({id_list[i], i}); //모든 유저의 name을 키값으로 answer에서의 해당 유저 인덱스를 value로 맵에 따로 저장
        userList.push_back({0, set<int>()}); //모든 유저의 {신고당한횟수, 신고자목록} 목록을 벡터로 생성
    }
    for (int i = 0; i < comSize; i++) {
        temp = report[i];
        mid = temp.find(" ");
        a = temp.substr(0, mid);
        b = temp.substr(mid + 1, temp.length()); //여기까지 신고자 a, 피신고자 b 저장

        t1 = userIndex.find(a)->second; //userIndex map 에서 유저 이름을 key로 검색하여 해당 유저의 인덱스가 몇번인지 찾아서 t1에 저장
        t2 = userIndex.find(b)->second; //마찬가지로 t2에 저장

        if (userList[t2].reporter.find(t1) == userList[t2].reporter.end()) {//t1이 t2를 처음 신고한거면
            userList[t2].reporter.insert(t1); // t2의 reporter 목록에 t1 추가
            userList[t2].reportCount++; //t2의 신고당한횟수 1 증가
        }
    }

    for (int i = 0; i < userSize; i++) { //모든 신고를 다 처리했으므로 이제 answer에 유저별 메일받을횟수 갱신
        if (userList[i].reportCount >= k) { //i번째 유저가 k회 이상 신고를 당했으면
            tempSize = userList[i].reporter.size(); //신고자 각각에 대해서
            for (int j = 0; j < tempSize; j++) {
                answer[*userList[i].reporter.begin()]++; //reporter set의 앞에서부터 해당 유저의 answer값을 1증가하고
                userList[i].reporter.erase(userList[i].reporter.begin()); //처리가 끝난 유저는 reporter set에서 삭제
            }
        }
    }

    return answer; //정보가 모두 갱신된 answer을 반환한다.
}
