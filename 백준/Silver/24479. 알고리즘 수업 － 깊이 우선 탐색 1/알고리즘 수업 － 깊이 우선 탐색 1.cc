#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited(999999, 0);
int cnt = 0;

void dfs(int n, vector<int> head_tail[], int r)
{
    if (visited[r] == 1) return;
    
    cnt++;
    visited[r] = cnt;
    
    for (int i = 0; i < head_tail[r].size(); i++) {
        if (visited[head_tail[r][i]] == 0)
            dfs(n, head_tail, head_tail[r][i]);
    }
}

int main(void)
{
    int n, m, r;
    
    cin >> n >> m >> r;
    vector<int> head_tail[n];
    
    for (int i = 0; i < m; i++) {
        int head, tail;
        cin >> head >> tail;
        head_tail[head - 1].push_back(tail - 1);
        head_tail[tail - 1].push_back(head - 1);
    }
    
    for (int i = 0; i < n; i++)
        sort(head_tail[i].begin(), head_tail[i].end());
    
    dfs(n, head_tail, r - 1);
    
    for (int i = 0; i < n; i++)
        cout << visited[i] << '\n';
    
    return 0;
}
