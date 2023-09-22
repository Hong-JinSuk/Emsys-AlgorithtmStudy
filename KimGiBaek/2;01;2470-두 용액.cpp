#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, zero, yongak[111111];
long long mini = 99999999999999;//가장작은숫자저장용
pair<int, int> srch, minpos, mp;//srch: search라는뜻~탐색중인위치를표시하는것입니다.
                                //minpos: 가장 작은 조합 두놈 위치 저장하는것입니다.
                                //mp: 마이너스플러스 개수 센겁니다. 왼쪽이마이너스

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &yongak[i]);
        if (yongak[i] < 0)
            mp.first++;
        else if (yongak[i] > 0)
            mp.second++;
        else if (++zero >= 2) //0두개면 그냥 걔네로 끝이니까 더입력도안받고 쿨하게 종료
        {
            printf("0 0");
            return 0;
        }
    }
    sort(yongak, yongak + n);
    if (!mp.first) //마이너스가없으면?? 앞에둘합친게 젤작겠죠
    {
        printf("%d %d", yongak[0], yongak[1]);
        return 0;
    }
    else if (!mp.second) //플러스가없으면?? 뒤에둘합친게 젤작겠죠
    {
        printf("%d %d", yongak[n - 2], yongak[n - 1]);
        return 0;
    }
    srch.first = mp.first - 1; //대충 0에가까운 중간쯤부터 탐색 시작한다는 뜻ㅎ
    srch.second = mp.first;
    if (mp.first >= 2) //아니근데세상에 마이너스하나 플러스하나 합친거보다 한쪽에서 젤작은 둘 합친게 더 작은 어이없는 반례가 있더라고요 그거 걸러줍니다
    {
        mini = -(yongak[mp.first - 2] + yongak[mp.first - 1]);
        minpos.first = mp.first - 2;
        minpos.second = mp.first - 1;
    }
    if (mp.second >= 2)
    {
        mini = min(mini, (long long)yongak[mp.first] + yongak[mp.first + 1]);
        minpos.first = mp.first;
        minpos.second = mp.first + 1;
    }
    while (1) //젤작은거찾는과정
    {
        int yonghap = yongak[srch.first] + yongak[srch.second];
        if (yonghap == 0) //합쳐서0이면끝이죠?더작은거없죠?
        {
            printf("%d %d", yongak[srch.first], yongak[srch.second]);
            return 0;
        }
        else if (abs(yonghap) < mini) //최소값 갱신되면 최소값이랑 그 두개 위치 저장
        {
            mini = abs(yonghap);
            minpos.first = srch.first;
            minpos.second = srch.second;
        }
        if (yonghap < 0 && srch.second < n - 1) //합쳐서 마이너스면 플러스쪽 더 큰거 가져오기
        {
            srch.second++;
            continue;
        }
        else if (yonghap > 0 && srch.first > 0) //합쳐서 플러스면 마이너스쪽 더 큰거 가져오기
        {
            srch.first--;
            continue;
        }
        break;
    }
    printf("%d %d", yongak[minpos.first], yongak[minpos.second]);
}
