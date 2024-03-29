#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc;
int v, e;
int visited[20000] = {0, };
string answer = "YES";

void init_visited()
{
    for (int i = 0; i < v; i++)
        visited[i] = 0;
}

void dfs(vector<int> edge[], int pos, int color)  // color : 1 / 2
{
    if (visited[pos] != 0) return;
    
    visited[pos] = color;
    
    for (int i = 0; i < edge[pos].size(); i++) {
        int next = edge[pos][i];
        int next_color;
        if (color == 1) next_color = 2;
        else next_color = 1;
        if (!visited[next])
            dfs(edge, next, next_color);
        else if (visited[next] == visited[pos]) {
            answer = "NO";
            return;
        }
    }
}

int main(void)
{
    cin >> tc;
    
    for (int t = 0; t < tc; t++) {
        cin >> v >> e;
        vector<int> edge[v];
        for (int i = 0; i < e; i++) {
            int head, tail;
            cin >> head >> tail;
            edge[head - 1].push_back(tail - 1);
            edge[tail - 1].push_back(head - 1);
        }
        for (int i = 0; i < v; i++) {
            sort(edge[i].begin(), edge[i].end());
            edge[i].erase(unique(edge[i].begin(), edge[i].end()), edge[i].end());
        }
        init_visited();
        answer = "YES";
        int color = 1;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(edge, i, color);
                color = 3 - color;
            }
        }
        // dfs(edge, 0, 1);
        cout << answer << '\n';
    }
}
