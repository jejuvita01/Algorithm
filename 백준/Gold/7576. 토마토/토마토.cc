#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, m;
int map[1000][1000];
int visited[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer = 0;
deque<pair<int, int>> dq;

void bfs(void)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                dq.push_back(make_pair(i, j));
            }
        }
    }
    
    for (int i = 0; i < dq.size(); i++)
        visited[dq[i].first][dq[i].second] = 0;
    
    while (dq.size() != 0) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        int new_x, new_y;
        for (int i = 0; i < 4; i++) {
            new_x = x + dx[i];
            new_y = y + dy[i];
            if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
                if (!visited[new_x][new_y] && map[new_x][new_y] == 0) {
                    map[new_x][new_y] = 1;
                    dq.push_back(make_pair(new_x, new_y));
                    visited[new_x][new_y] = visited[x][y] + 1;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 0)
                answer = -1;
    
    if (answer != -1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (answer < visited[i][j])
                    answer = visited[i][j];
            }
        }
    }
}

int main(void)
{
    cin >> m >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            map[i][j] = x;
        }
    }
    
    bfs();
    
    cout << answer << '\n';
    
    return 0;
}
