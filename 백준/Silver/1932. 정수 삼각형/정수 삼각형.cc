#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dp(vector<vector<int>>& num, int lines)
{
    for (int i = 1; i < lines; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) { // 왼쪽 끝
                num[i][j] += num[i - 1][j];
            }
            else if (j == i) { // 오른쪽 끝
                num[i][j] += num[i - 1][j - 1];
            }
            else { // 가운데
                num[i][j] += max(num[i - 1][j - 1], num[i - 1][j]);
            }
        }
    }
    
    return;
}

int main(void)
{
    int line;
    vector<vector<int>> num;
    int answer = 0;
    
    cin >> line;
    
    for (int i = 1; i <= line; i++) {
        int n;
        vector<int> tmp;
        for (int j = 0; j < i; j++) {
            cin >> n;
            tmp.push_back(n);
        }
        num.push_back(tmp);
    }
    
    dp(num, line);
    
    for (int i = 0; i < line; i++) {
        if (num[line - 1][i] > answer)
            answer = num[line - 1][i];
    }
    
    cout << answer << endl;
    
    return 0;
}
