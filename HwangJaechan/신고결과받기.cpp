#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string,int>reported;
map<string,set<string>>reports;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(auto i : report){
        int tmp = i.find(' ');
        string str1 = i.substr(0,tmp);
        string str2 = i.substr(tmp+1);
        if(reports[str1].find(str2)!=reports[str1].end()){
            continue;
        }
        else{
            reports[str1].insert(str2);
            reported[str2]++;
        }
    }
    for(auto i : id_list){
        int cup = 0;
        for(auto j : reports[i]){
            if(reported[j]>=k)cup++;
        }
        answer.push_back(cup);
    }
    return answer; 
}
