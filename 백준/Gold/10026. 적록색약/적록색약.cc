#include <iostream>
#include <vector>

using namespace std;

void change_R_to_G(int n, vector<vector<char>>& mat)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'R')
                mat[i][j] = 'G';
        }
    }
}

void dfs(int n, vector<vector<char>>& mat, vector<vector<int>>& visited, int i, int j, char c)
{
    if (visited[i][j]) return;
    visited[i][j] = 1;
    if (i - 1 >= 0 && !visited[i - 1][j] && mat[i - 1][j] == c) { // 상
        dfs(n, mat, visited, i - 1, j, c);
    }
    if (i + 1 < n && !visited[i + 1][j] && mat[i + 1][j] == c) { // 하
        dfs(n, mat, visited, i + 1, j, c);
    }
    if (j - 1 >= 0 && !visited[i][j - 1] && mat[i][j - 1] == c) { // 좌
        dfs(n, mat, visited, i, j - 1, c);
    }
    if (j + 1 < n && !visited[i][j + 1] && mat[i][j + 1] == c) { // 우
        dfs(n, mat, visited, i, j + 1, c);
    }
    
    return;
}

int main(void)
{
    int n;
    vector<vector<char>> mat;
    int answer = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        vector<char> tmp;
        char c;
        for (int j = 0; j < n; j++) {
            cin >> c;
            tmp.push_back(c);
        }
        mat.push_back(tmp);
    }
    
    // 적록색맹이 아닌 사람
    vector<vector<int>> visited(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                answer++;
                dfs(n, mat, visited, i, j, mat[i][j]);
            }
        }
    }
    cout << answer << ' ';
    
    // 적록색맹인 사람
    fill(visited.begin(), visited.end(), vector<int>(n, 0));
    answer = 0;
    change_R_to_G(n, mat);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                answer++;
                dfs(n, mat, visited, i, j, mat[i][j]);
            }
        }
    }
    cout << answer << endl;
    
    return 0;
}
