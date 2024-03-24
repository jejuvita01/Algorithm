#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int tc, l, knight_x, knight_y, dest_x, dest_y;
int map[300][300] = {0, };
int ans[300][300] = {0, };
int visited[300][300] = {0, };
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void init(void)
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            visited[i][j] = 0;
            ans[i][j] = 0;
        }
    }
}

void bfs(void)
{
    deque<pair<int, int>> dq;
    int new_x, new_y;
    
    for (int i = 0; i < 8; i++) {
        new_x = knight_x + dx[i];
        new_y = knight_y + dy[i];
        if (0 <= new_x && new_x < l && 0 <= new_y && new_y < l)
            visited[new_x][new_y] = 0;
    }
    
    dq.push_back(make_pair(knight_x, knight_y));
    visited[knight_x][knight_y] = 1;
    ans[knight_x][knight_y] = 0;
    
    while (dq.size() != 0) {
        int f_x = dq.front().first;
        int f_y = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 8; i++) {
            new_x = f_x + dx[i];
            new_y = f_y + dy[i];
            if (0 <= new_x && new_x < l && 0 <= new_y && new_y < l) {
                if (visited[new_x][new_y] == 0) {
                    visited[new_x][new_y] = 1;
                    dq.push_back(make_pair(new_x, new_y));
                    ans[new_x][new_y] = ans[f_x][f_y] + 1;
                }
                if (new_x == dest_x && new_y == dest_y)
                    break;
            }
        }
    }
}

int main(void)
{
    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        init();
        cin >> l >> knight_x >> knight_y >> dest_x >> dest_y;
        bfs();
        cout << ans[dest_x][dest_y] << '\n';
    }
    
    return 0;
}
