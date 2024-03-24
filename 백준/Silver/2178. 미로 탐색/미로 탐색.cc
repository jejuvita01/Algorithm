#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;
int map[100][100];
int visited[100][100] = {0, };
int min_move[100][100] = {100 * 100, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int new_x, new_y;
deque<pair<int, int>> dq;


void bfs(int x, int y, int cnt) {
    for (int i = 0; i < 4; i++) {
        new_x = x + dx[i];
        new_y = y + dy[i];
        if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
            visited[new_x][new_y] = 0;
        }
    }
    
    visited[x][y] = 1;
    min_move[x][y] = cnt;
    dq.push_back(make_pair(x, y));
    
    while (dq.size() != 0) {
        int r, c;
        r = dq.front().first;
        c = dq.front().second;
        dq.pop_front();
        cnt++;
        for (int i = 0; i < 4; i++) {
            new_x = r + dx[i];
            new_y = c + dy[i];
            if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
                if (!visited[new_x][new_y] && map[new_x][new_y] == 1) {
                    visited[new_x][new_y] = 1;
                    dq.push_back(make_pair(new_x, new_y));
                    min_move[new_x][new_y] = min_move[r][c] + 1;
                }
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;
    string str;
    
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++)
            map[i][j] = str[j] - '0';
    }
    
    bfs(0, 0, 1);
    
    cout << min_move[n - 1][m - 1] << '\n';
    
    return 0;
}
