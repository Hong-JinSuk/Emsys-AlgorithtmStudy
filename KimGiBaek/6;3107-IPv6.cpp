#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

char adr[44];
queue<string> stk;

int main() {
    string str = "";
    scanf("%s", adr);
    int s = strlen(adr);
    for(int i=0; i<s; i++){
        if(adr[i]==':'){                           //콜론을 만나면
            if(str != ""){                         //문자열이 비어있지 않은 경우에(처음부터 "::"이 나오면 비어있을 수 있음)
                for(int j=str.length(); j<4; j++){ //문자열이 4자보다 적으면
                    str = '0'+str;                 //앞에 부족한 만큼 0 달아주기
                }
                stk.push(str);
                str = "";
            }
            if(adr[i+1]==':'){ // ':'이 연속으로 두 번 나온 경우
                stk.push("X"); //큐에 X 넣기: 콜론 두개짜리가 여기 있다는 뜻
                str = "";
                i++;           //두칸 탐색했으니까 건너뛰어주기
            }
        }else{
            str += adr[i]; //앞에서부터 한글자씩 str에 쌓아주기(':' 만날때까지)
        }
    }
    if(str != ""){                          //주소의 마지막은 콜론을 만나지 않고 끝나니까 마지막에 쌓인것도 넣어주려는데
        for(int j=str.length(); j<4; j++){  //"::"으로 끝나면 문자열이 비어있을 수 있어서 비어있지 않은 경우로 걸러주기:
            str = '0'+str;                  // 처음에 이거 안거르고 다 넣었다가 틀림
        }
        stk.push(str);
    }
    int i = stk.size();         //큐 사이즈로 X가 0000을 몇 개 생략한건지 알 수 있음
    while(1){                   //콜론 찍으려는데 while(!stk.empty()) 로 돌리면 콜론찍기 애매해져서 무한반복 돌린거같음
        if(stk.front() == "X"){ //X가 나오면
            for(; i<=8; i++){   //큐 사이즈랑 비교해서 부족한 만큼 0000 채워주기
                printf("0000");
                if(i<=7)        //끝에는 콜론 안찍으니까 끝이 아닐때만 찍기
                    printf(":");
            }
        }
        else
            printf("%s", stk.front().c_str());  //X아니면 4개씩 잘 채워뒀으니 그냥출력
        stk.pop();
        if(stk.empty())
            break;
        else{
            printf(":");
        }
    }
}
