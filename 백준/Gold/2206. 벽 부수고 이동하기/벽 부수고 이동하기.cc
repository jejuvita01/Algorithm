#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int n, m;
int map[1000][1000];
int visited[1000][1000][2] = {0, }; // x, y, 벽 부순 여부(부쉈으면 1, 아니면 0)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

typedef struct {
    int x;
    int y;
} point;

deque<pair<point, int>> dq;

int bfs(void)
{
    point ori, next;
    int did_break;
    
    ori.x = ori.y = did_break = 0;
    visited[ori.x][ori.y][did_break] = 1;
    dq.push_back(make_pair(ori, did_break));
    
    while (dq.size() != 0) {
        ori.x = dq.front().first.x;
        ori.y = dq.front().first.y;
        did_break = dq.front().second;
        dq.pop_front();
        if (ori.x == n - 1 && ori.y == m - 1)
            return visited[ori.x][ori.y][did_break];
        for (int i = 0; i < 4; i++) {
            next.x = ori.x + dx[i];
            next.y = ori.y + dy[i];
            
            if (0 <= next.x && next.x < n && 0 <= next.y && next.y < m) {
                if (map[next.x][next.y] == 1 && did_break == 0) { // 다음 칸이 벽이고 부술 수 있을 때
                    visited[next.x][next.y][1] = visited[ori.x][ori.y][did_break] + 1;
                    dq.push_back(make_pair(next, 1));
                }
                else if (map[next.x][next.y] == 0 && visited[next.x][next.y][did_break] == 0) { // 다음 칸이 벽이 아니고 방문하지 않았을 때
                    visited[next.x][next.y][did_break] = visited[ori.x][ori.y][did_break] + 1;
                    dq.push_back(make_pair(next, did_break));
                }
            }
        }
    }
    
    return -1;
}

int main(void)
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            map[i][j] = str[j] - '0';
    }
    
    cout << bfs() << '\n';
    
    return 0;
}
