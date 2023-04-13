#include <cstring>
#include <stdio.h>

int main() {
    char s[1000101], t[40], s2[1000101];
    int sl, tl;
    scanf("%s", s);
    scanf("%s", t);
    sl = strlen(s);
    tl = strlen(t); //길이저장: strlen 많이쓰면 오래걸림
    int k = 0;      //뒤로 빠꾸한 칸 수
    for (int i = 0; i < sl; i++) {                 //첫 문자열 s를 s2에 옮기면서 진행하기 위해 s의 길이만큼 반복
        s2[i-k] = s[i];                             //옮기고
        s2[i-k+1] = '\0';                            //그 다음칸 막기
        if (i-k+1 >= tl){                             //s2에 옮겨진 문자열의 길이가 폭발 문자열의 길이보다 크거나 같으면
            bool yes = !strncmp(&s2[i-k-tl+1], t, tl); //폭발 문자 있는지 끝부분만 폭발 문자열의 길이만큼 확인
            if (yes){                                   //폭발 문자열이 있으면
                k += tl;                                 //터뜨리고 폭발 문자열의 길이만큼 빠꾸
                s2[i - k + 1] = '\0';
            }
        }
    }
    if (s2[0] == '\0')   //다 터졌으면 FRULA 출력
        printf("FRULA");
    else                 //아니면 남은 문자열 출력
        printf("%s", s2);
    return 0;
}
