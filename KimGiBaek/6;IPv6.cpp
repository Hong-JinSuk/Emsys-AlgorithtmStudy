#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

char adr[44];
std::queue<std::string> stk;

int main() {
    std::string str = "";
    scanf("%s", adr);
    int s = strlen(adr);
    for(int i=0; i<s; i++){
        if(adr[i]==':'){
            if(str != ""){
                for(int j=str.length(); j<4; j++){
                    str = '0'+str;
                }
                stk.push(str);
                str = "";
            }
            if(adr[i+1]==':'){
                stk.push("X");
                str = "";
                i++;
            }
        }else{
            str += adr[i];
        }
    }
    if(str != ""){
        for(int j=str.length(); j<4; j++){
            str = '0'+str;
        }
        stk.push(str);
    }
    int i = stk.size();
    while(1){
        if(stk.front() == "X"){
            for(; i<=8; i++){
                printf("0000");
                if(i<=7)
                    printf(":");
            }
        }
        else
            printf("%s", stk.front().c_str());
        stk.pop();
        if(stk.empty())
            break;
        else{
            printf(":");
        }
    }
}
