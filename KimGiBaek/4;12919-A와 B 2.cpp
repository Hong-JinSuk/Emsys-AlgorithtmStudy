#include <cstdio>
#include <cstring>

char s[55], t[55];
int sl,tl;

int split(int h, int e, bool rev);

int main() {
    scanf("%s", s);
    scanf("%s", t);
    sl = strlen(s);
    tl = strlen(t);
    printf("%d", split(0, tl-1, false));
    return 0;
}

int split(int h, int e, bool rev) //h=첫 문자, e=마지막 문자, rev=뒤집힌 문자열인지 여부:
{                                 //직접 문자열 뒤집으면 시간 많이 잡아먹을까봐 뒤집었다고 치고 거꾸로 탐색하기
    if(e-h+1<=sl){               //줄어든 문자열의 길이가 시작 문자열 S의 길이와 같아졌을 때
        for(int i=0; i<sl; i++){ //줄어든 문자열이 시작 문자열 S와 같은지 비교
            if(rev){
                if(t[e-i]!=s[i]){
                    return 0;
                }
            }
            else{
                if(t[i+h]!=s[i]){
                    return 0;
                }
            }
        }
        return 1;
    }
    else{
        if(rev){ //뒤집어진 문자열일 경우 거꾸로 탐색
            if(t[h]=='A' && t[e]=='B')
                return split(h+1,e,rev)||split(h,e-1,!rev);
            else if(t[h]=='A')
                return split(h+1,e,rev);
            else if(t[e]=='B')
                return split(h,e-1,!rev);
            else return 0;
        }
        else{ //뒤집어지지 않은 문자열일 경우
            if(t[e]=='A' && t[h]=='B')                      //마지막 문자가 A이고 첫 문자가 B일때
                return split(h,e-1,rev)||split(h+1,e,!rev); //경우의 수 모두 확인. 원래 + 쓸랬는데 1과 0으로 출력이라 OR 사용
            else if(t[e]=='A')                              //B*A가 아니고 마지막 문자가 A일 때: ex)ABA
                return split(h,e-1,rev);                    //마지막 한 칸 지우기
            else if(t[h]=='B')                              //첫 문자가 B일 때: ex)BAB
                return split(h+1,e,!rev);                   //첫 칸 지우고 뒤집기
            else return 0;                                  //모두 아닐 때(A*B)는 주어진 두 가지 연산으로 만들 수 없는 경우니까 죽이기
        }
    }
}
