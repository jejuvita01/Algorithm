#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, r;
vector<int> head_tail[1000000];
vector<int> dfs_answer;
vector<int> bfs_answer;
int visited[1000000] = {0, };
deque<int> dq;

void dfs(int r)
{
    if (visited[r] == 1) return;
    
    visited[r] = 1;
    dfs_answer.push_back(r + 1);
    
    for (int i = 0; i < head_tail[r].size(); i++) {
        if (!visited[head_tail[r][i]])
            dfs(head_tail[r][i]);
    }
}

void bfs(int r)
{
    for (int i = 0; i < head_tail[r].size(); i++)
        visited[head_tail[r][i]] = 0;
    
    visited[r] = 1;
    bfs_answer.push_back(r + 1);
    
    dq.push_back(r);
    
    while (dq.size() != 0) {
        int u = dq.front();
        dq.pop_front();
        for (int i = 0; i < head_tail[u].size(); i++) {
            if (visited[head_tail[u][i]] == 0) {
                visited[head_tail[u][i]] = 1;
                bfs_answer.push_back(head_tail[u][i] + 1);
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
    
    for (int i = 0; i < n; i++) {
        sort(head_tail[i].begin(), head_tail[i].end());
        head_tail[i].erase(unique(head_tail[i].begin(), head_tail[i].end()), head_tail[i].end());
    }
    
    dfs(r - 1);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    bfs(r - 1);
    
    for (int i = 0; i < dfs_answer.size(); i++)
        cout << dfs_answer[i] << ' ';
    cout << '\n';
    for (int i = 0; i < bfs_answer.size(); i++)
        cout << bfs_answer[i] << ' ';
    
    return 0;
}
