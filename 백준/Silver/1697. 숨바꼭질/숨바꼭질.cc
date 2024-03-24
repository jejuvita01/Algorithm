#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int start, finish;
int visited[100000 + 1] = {0, };
int ans[100000 + 1];
deque<int> dq;

void bfs(void)
{
    if (0 <= start - 1)
        visited[start - 1] = 0;
    if (start + 1 <= 100000)
        visited[start + 1] = 0;
    if (start * 2 <= 100000)
        visited[start * 2] = 0;
    
    visited[start] = 1;
    ans[start] = 0;
    dq.push_back(start);
    
    int minus, plus, mul; // 여기 초기화부터 while문 안에 있는거 없애도 되는지 생각해보기
    while (dq.size() != 0) {
        int f = dq.front();
        dq.pop_front();
        minus = f - 1;
        plus = f + 1;
        mul = f * 2;
        if (0 <= minus && !visited[minus]) {
            visited[minus] = 1;
            ans[minus] = ans[f] + 1;
            dq.push_back(minus);
        }
        if (plus <= 100000 && !visited[plus]) {
            visited[plus] = 1;
            ans[plus] = ans[f] + 1;
            dq.push_back(plus);
        }
        if (mul <= 100000 && !visited[mul]) {
            visited[mul] = 1;
            ans[mul] = ans[f] + 1;
            dq.push_back(mul);
        }
        if (minus == finish || plus == finish || mul == finish)
            break;
    }
}

int main(void)
{
    cin >> start >> finish;
    
    bfs();
    
    cout << ans[finish] << '\n';
    
    return 0;
}
