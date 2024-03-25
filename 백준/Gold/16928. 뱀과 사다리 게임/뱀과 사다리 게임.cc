#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int ladder, snake;
int pos = 0;
int map[100] = {0, };
int visited[100] = {0, };
deque<int> dq;

void bfs(void)
{
    dq.push_back(pos);
    visited[pos] = 0;
    
    while (dq.size() != 0) {
        int pos = dq.front();
        dq.pop_front();
        for (int i = 1; i <= 6; i++) {
            int new_pos = pos + i;
            if (new_pos < 100 && map[new_pos] != 0)
                new_pos = map[new_pos];
            if (new_pos < 100 && !visited[new_pos]) {
                dq.push_back(new_pos);
                visited[new_pos] = visited[pos] + 1;
            }
            if (new_pos == 100 - 1)
                break;
        }
    }
}

int main(void)
{
    cin >> ladder >> snake;
    
    for (int i = 0; i < ladder; i++) {
        int x, y;
        cin >> x >> y;
        map[x - 1] = y - 1;
    }
    
    for (int i = 0; i < snake; i++) {
        int x, y;
        cin >> x >> y;
        map[x - 1] = y - 1;
    }
    
    bfs();
    
    cout << visited[100 - 1] << '\n';
    
    return 0;
}
