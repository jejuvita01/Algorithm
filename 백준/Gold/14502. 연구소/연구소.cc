#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int n, m;
int map[8][8];
int new_map[8][8];
int visited[8][8];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void init_visited(void)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
}

void get_map_info(void)
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}

void copy_map(void)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            new_map[i][j] = map[i][j];
}

bool is_inside(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int arr[8][8], int x, int y)
{
    arr[x][y] = 2;
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (is_inside(new_x, new_y)) {
            if (arr[new_x][new_y] != 1 && visited[new_x][new_y] == 0) {
                dfs(arr, new_x, new_y);
            }
        }
    }
}

void spread_virus(int arr[8][8])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2 && visited[i][j] == 0)
                dfs(arr, i, j);
        }
    }
}

int cnt_safe(int arr[8][8])
{
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0)
                cnt++;
        }
    }
    
    return cnt;
}

void print_map(int arr[8][8]) {
    cout << "\n MAP \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void)
{
    int max_safe = 0;
    
    get_map_info();
    
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            if (map[i1][j1] == 0) {
                for (int i2 = i1; i2 < n; i2++) {
                    for (int j2 = 0; j2 < m; j2++) {
                        if (map[i2][j2] == 0) {
                            if (i2 == i1 && j2 <= j1)
                                continue;
                            else {
                                for (int i3 = i2; i3 < n; i3++) {
                                    for (int j3 = 0; j3 < m; j3++) {
                                        if (map[i3][j3] == 0) {
                                            if (i3 == i2 && j3 <= j2)
                                                continue;
                                            else {
                                                copy_map();
                                                new_map[i1][j1] = 1;
                                                new_map[i2][j2] = 1;
                                                new_map[i3][j3] = 1;
                                                init_visited();
                                                spread_virus(new_map);
                                                max_safe = max(max_safe, cnt_safe(new_map));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << max_safe << '\n';
    
    return 0;
}
