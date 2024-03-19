#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited(101, 0);
int cnt = 0;

void dfs(int start, vector<int> list[])
{
    if (visited[start] == 1) return;
    
    visited[start] = 1;
    cnt++;
    
    for (int i = 0; i < list[start].size(); i++) {
        if (visited[list[start][i]] == 0)
            dfs(list[start][i], list);
    }
}

int main(void)
{
    int n, v;
    
    cin >> n >> v;
    vector<int> list[n];
    
    for (int i = 0; i < v; i++) {
        int head, tail;
        cin >> head >> tail;
        list[head - 1].push_back(tail - 1);
        list[tail - 1].push_back(head - 1);
    }
    
    dfs(1 - 1, list);
    
    cout << (cnt > 0 ? cnt - 1 : cnt) << '\n';
    
    return 0;
}
