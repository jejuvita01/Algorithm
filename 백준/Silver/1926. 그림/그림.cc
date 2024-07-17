#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

#define SZ 500

typedef struct Point {
    int x;
    int y;
} point;

int n, m;
int map[SZ][SZ];
int visited[SZ][SZ];
int cnt = 0;
int max_size = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

deque<point> dq;

void init_visited(void)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
}

bool is_inside(point p)
{
    return (0 <= p.x && p.x < n && 0 <= p.y && p.y < m);
}

void bfs(point p, int& size)
{
    size++;
    visited[p.x][p.y] = 1;
    dq.push_back(p);
    
    while (dq.size() != 0) {
        point now = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            point next = {now.x + dx[i], now.y + dy[i]};
            if (is_inside(next)) {
                if (map[next.x][next.y] == 1 && visited[next.x][next.y] == 0) {
                    bfs(next, size);
                }
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    
    init_visited();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                cnt++;
                point p = {i, j};
                int size = 0;
                bfs(p, size);
                if (size > max_size)
                    max_size = size;
            }
        }
    }
    
    cout << cnt << '\n' << max_size << '\n';
    
    return 0;
}
