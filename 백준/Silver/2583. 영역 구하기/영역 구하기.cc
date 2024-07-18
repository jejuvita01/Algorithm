#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

#define SZ 100

typedef struct Point {
    int x;
    int y;
} point;

int n, m, rec_num;
int map[SZ][SZ] = {0, };
int visited[SZ][SZ];
int cnt;
vector<int> sizes;
deque<point> dq;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init_visited(void)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
}

void color_map(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            map[i][j] = 1;
        }
    }
}

void print_map(void)
{
    cout << "\nMAP\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool is_inside(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs(int x, int y, int& size)
{
    size++;
    visited[x][y] = 1;
    point p = {x, y};
    dq.push_back(p);
    
    while (dq.size() != 0) {
        p = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            point tmp = {p.x + dx[i], p.y + dy[i]};
            if (is_inside(tmp.x, tmp.y) && map[tmp.x][tmp.y] == 0 && visited[tmp.x][tmp.y] == 0) {
                bfs(tmp.x, tmp.y, size);
            }
        }
    }
    
    return;
}

int main(void)
{
    cin >> m >> n >> rec_num;
    
    for (int i = 0; i < rec_num; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        color_map(x1, y1, x2, y2);
    }
    
    // print_map();
    
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && visited[i][j] == 0) {
                cnt++;
                int size = 0;
                bfs(i, j, size);
                sizes.push_back(size);
            }
        }
    }
    
    sort(sizes.begin(), sizes.end());
    
    cout << cnt << '\n';
    
    for (int i = 0; i < cnt; i++)
        cout << sizes[i] << ' ';
    cout << '\n';
    
    return 0;
}
