#include <iostream>
#include <vector>
#include <string>

using namespace std;
string s;
string olds;


void make4(int index, int ok) {
    int cnt=0;
    int i=1;

    while(s[index-i]!= ':') {
        cnt++;
        i++;
    }
    
    for(int i=4; i>=1; i--) {
        if(i!=cnt){
            olds.push_back('0');
        }else{
            olds.push_back(s[index-cnt]);
            cnt--;
        }
    }

    olds.push_back(':');
    if(ok) {
        olds.push_back(':');
    }
    

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int s_len;

    cin >> s;
    
    s.insert(0, ":");
    s.push_back(':');
    s_len = s.length();

    for(int i=1; i<s_len; i++) {
        if(s[i]==':') {
            if(s[i+1]==':' && i+1!=s_len-1) {
                make4(i, 1);
            }else {
                make4(i, 0);
            }
        }
    }
    while(olds.length() < 39) {
        t = olds.find("::");
        olds.insert(t, ":0000");
    }
    
    olds.erase(olds.end() - 1);
    
    t = olds.find("::");
    if(t!=string::npos) {
        while(olds.length() != 39) {
            olds.erase(t, 1);
        }
        
    }

    cout << olds;

    return 0;
}
