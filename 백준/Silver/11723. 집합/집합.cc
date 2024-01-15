#include <iostream>
#include <cstring>

using namespace std;

/*
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.
*/

#define SZ 20 + 1

void all(int s[SZ], int x)
{
    for (int i = 1; i < SZ; i++)
        s[i] = x;
    
    return;
}

int main(void)
{
    int s[SZ] = { 0 };
    int n;
    char str[SZ];
    int x;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (strcmp(str, "all") == 0)
            all(s, 1);
        else if (strcmp(str, "empty") == 0)
            all(s, 0);
        else {
            scanf("%d", &x);
            if (strcmp(str, "add") == 0)
                s[x] = 1;
            else if (strcmp(str, "remove") == 0)
                s[x] = 0;
            else if (strcmp(str, "check") == 0) {
                if (s[x] == 1)
                    printf("1\n");
                else
                    printf("0\n");
            }
            else if (strcmp(str, "toggle") == 0)
                s[x] == 1 ? s[x] = 0 : s[x] = 1;
        }
        if (i == n - 1) {
            i = n;
        }
    }
    
    return 0;
}
