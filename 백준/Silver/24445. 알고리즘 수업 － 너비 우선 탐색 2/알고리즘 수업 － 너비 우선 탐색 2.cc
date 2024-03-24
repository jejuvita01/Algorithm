#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, r;
vector<int> head_tail[1000000];
int answer[1000000];
int visited[1000000] = {0, };
deque<int> dq;
int order = 1;

void bfs(int r)
{
    for (int i = 0; i < head_tail[r].size(); i++)
        visited[head_tail[r][i]] = 0;
    
    visited[r] = 1;
    answer[r] = order;
    order++;
        
    dq.push_back(r);
    
    while (dq.size() != 0) {
        int u = dq.front();
        dq.pop_front();
        for (int i = head_tail[u].size() - 1; i >= 0; i--) {
            if (visited[head_tail[u][i]] == 0) {
                visited[head_tail[u][i]] = 1;
                answer[head_tail[u][i]] = order;
                order++;
                dq.push_back(head_tail[u][i]);
            }
        }
    }
}

int main(void)
{
    cin >> n >> m >> r;
    
    for (int i = 0; i < m; i++) {
        int head, tail;
        cin >> head >> tail;
        head_tail[head - 1].push_back(tail - 1);
        head_tail[tail - 1].push_back(head - 1);
    }
    
    for (int i = 0; i < n; i++)
        sort(head_tail[i].begin(), head_tail[i].end());
    
    bfs(r - 1);
    
    for (int i = 0; i < n; i++)
        cout << answer[i] << '\n';
    
    return 0;
}
