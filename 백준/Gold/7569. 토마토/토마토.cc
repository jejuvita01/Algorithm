#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m, h;
int map[100][100][100];
int visited[100][100][100];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int answer = 0;
deque<tuple<int, int, int>> dq;

void bfs(void)
{
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[k][i][j] == 1) {
                    dq.push_back(make_tuple(k, i, j));
                }
            }
        }
    }
    
    for (int i = 0; i < dq.size(); i++)
        visited[get<0>(dq[i])][get<1>(dq[i])][get<2>(dq[i])] = 0;
    
    while (dq.size() != 0) {
        int x = get<1>(dq.front());
        int y = get<2>(dq.front());
        int z = get<0>(dq.front());
        dq.pop_front();
        int new_x, new_y, new_z;
        for (int i = 0; i < 6; i++) {
            new_x = x + dx[i];
            new_y = y + dy[i];
            new_z = z + dz[i];
            if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m && 0 <= new_z && new_z < h) {
                if (!visited[new_z][new_x][new_y] && map[new_z][new_x][new_y] == 0) {
                    map[new_z][new_x][new_y] = 1;
                    dq.push_back(make_tuple(new_z, new_x, new_y));
                    visited[new_z][new_x][new_y] = visited[z][x][y] + 1;
                }
            }
        }
    }
    
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[k][i][j] == 0)
                    answer = -1;
            }
        }
    }
    
    if (answer != -1) {
        for (int k = 0; k < h; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (answer < visited[k][i][j])
                        answer = visited[k][i][j];
                }
            }
        }
    }
}

int main(void)
{
    cin >> m >> n >> h;
    
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                map[k][i][j] = x;
            }
        }
    }
    
    bfs();
    
    cout << answer << '\n';
    
    return 0;
}
