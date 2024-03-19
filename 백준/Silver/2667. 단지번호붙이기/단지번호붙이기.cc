#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int section = 0;
int cnt = 0;
vector<vector<int>> visited(25, vector<int>(25, 0));
vector<int> answer;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int n, int x, int y, vector<int> mat[], int& max)
{
    if (visited[x][y] == 1) {
        if (cnt > max)
            max = cnt;
        return;
    }
    
    visited[x][y] = 1;
    cnt++;
    
    int new_x, new_y;
    for (int k = 0; k < 4; k++) {
        new_x = x + dx[k];
        new_y = y + dy[k];
        if (0 <= new_x && new_x < n && 0 <= new_y && new_y < n) {
            if (mat[new_x][new_y] == 1) {
                if (cnt > max)
                    max = cnt;
                dfs(n, new_x, new_y, mat, max);
            }
        }
    }
}

int main(void)
{
    int n;
    int max;
    
    cin >> n;
    vector<int> mat[n];
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            mat[i].push_back(int(str[j] - '0'));
        }
    }
    
    max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0 && mat[i][j] == 1) {
                cnt = 0;
                max = 1;
                section++;
                dfs(n, i, j, mat, max);
                answer.push_back(max);
            }
            else
                visited[i][j] = 1;
        }
    }
    
    cout << section << '\n';
    
    // cout << answer.size() << '\n';
    
    sort(answer.begin(), answer.end());
    
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
    
    return 0;
}
