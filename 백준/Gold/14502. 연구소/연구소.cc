#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
vector<vector<int>> visited(8, vector<int>(8, 0));
vector<int> dfs_map[8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer = 0;


void print_map(vector<int> map[])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void init_visited(void)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
    
    return;
}

void dfs(vector<int> map[], int x, int y) // 감염시키며 탐색
{
    if (visited[x][y] == 1) return;
    
    map[x][y] = 2;
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
            if ((map[new_x][new_y] == 2 || map[new_x][new_y] == 0) && visited[new_x][new_y] == 0) {
                dfs(map, new_x, new_y);
            }
            else
                visited[new_x][new_y] = 1;
        }
    }
}

int cnt_safe(vector<int> map[]) // 안전한 위치 개수 세기
{
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0)
                count++;
        }
    }
    
    return count;
}

void copy_map(vector<int> origin[], vector<int> dest[]) // dest에 origin의 값 복사
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dest[i][j] = origin[i][j];
        }
    }
}

void make_wall(vector<int> new_map[], int wall) // 재귀로 벽 세개 세우기
{
    if (wall == 3) {
        init_visited();
        copy_map(new_map, dfs_map);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs_map[i][j] == 2 && visited[i][j] == 0) {
                    dfs(dfs_map, i, j);
                }
            }
        }
        answer = max(cnt_safe(dfs_map), answer);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (new_map[i][j] == 0) {
                new_map[i][j] = 1;
                make_wall(new_map, wall + 1);
                new_map[i][j] = 0;
            }
        }
    }
}


int main(void)
{
    cin >> n >> m;
    vector<int> original_map[n];
    vector<int> new_map[n];
    int wall;
    
    for (int i = 0; i < n; i++) {
        int x;
        for (int j = 0; j < m; j++) {
            cin >> x;
            original_map[i].push_back(x);
            new_map[i].push_back(x);
            dfs_map[i].push_back(x);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (original_map[i][j] == 0) {
                wall = 1;
                init_visited();
                copy_map(original_map, new_map);
                new_map[i][j] = 1;
                make_wall(new_map, 1);
                new_map[i][j] = 0;
            }
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
