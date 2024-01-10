#include <iostream>
#include <vector>

using namespace std;

int m, n, v;

void get_vertex(int n, vector<vector<int>> &mat)
{
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mat[y][x] = 1;
    }
    
    return;
}

bool dfs(int y, int x, vector<vector<int>> mat, vector<vector<int>> &visit)
{
    if (visit[y][x] == 1) return false;
    visit[y][x] = 1;
    
    vector<vector<int>> move(4, vector<int>(2, 0));
    move[0][0] = 0; move[0][1] = -1;
    move[1][0] = 0; move[1][1] = 1;
    move[2][0] = -1; move[2][1] = 0;
    move[3][0] = 1; move[3][1] = 0;
    
    for (int i = 0; i < 4; i++) {
        int a = x + move[i][0];
        int b = y + move[i][1];
        
        if (a >= 0 && b >= 0 && a < m && b < n && mat[b][a] == 1)
            dfs(b, a, mat, visit);
    }
    
    return true;
}

int main(void)
{
    int tc;
    
    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        int cnt = 0;
        cin >> m >> n >> v;
        vector<vector<int>> mat(51, vector<int>(51, 0));
        vector<vector<int>> visit(51, vector<int>(51, 0));
        get_vertex(v, mat);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (mat[r][c] == 1 && !visit[r][c]) {
                    if (dfs(r, c, mat, visit))
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    
    
    return 0;
}
