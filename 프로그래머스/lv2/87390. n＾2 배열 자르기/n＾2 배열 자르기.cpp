#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int left_row, left_col, right_row, right_col;
    
    left_row = left / n;
    left_col = left % n;
    right_row = right / n;
    right_col = right % n;
    
    if (left_row != right_row) {
        int r = left_row;
        int c = left_col;
        for (; r <= left_row; r++) {
            for (; c < n; c++) {
                answer.push_back(r > c ? r + 1 : c + 1);
            }
        }
        for (; r < right_row; r++) {
            for (c = 0; c < n; c++) {
                answer.push_back(r > c ? r + 1 : c + 1);
            }
        }
        for (; r <= right_row; r++) {
            for (c = 0; c <= right_col; c++) {
                answer.push_back(r > c ? r + 1 : c + 1);
            }
        }
    }
    
    else {
        for (int i = left_col; i <= right_col; i++)
            answer.push_back(left_row > i ? left_row + 1 : i + 1);
    }
    
    return answer;
}