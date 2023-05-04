#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_h, max_w;
    int max_index;
    
    // getting the max_h value
    max_h = max_w = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > max_h) {
            max_h = sizes[i][0];
            max_w = sizes[i][1];
            max_index = i;
        }
        else if (sizes[i][1] > max_h) {
            max_h = sizes[i][1];
            max_w = sizes[i][0];
            max_index = i;
        }
        else if (sizes[i][0] == max_h) {
            if (sizes[i][1] > max_w) {
                max_w = sizes[i][1];
                max_index = i;
            }
        }
        else if (sizes[i][1] == max_h) {
            if (sizes[i][0] > max_w) {
                max_w = sizes[i][0];
                max_index = i;
            }
        }
    }
    
    // compare every elements and update max_w
    for (int i = 0; i < sizes.size(); i++) {
        if (i != max_index) {
            if (!((sizes[i][0] <= max_h && sizes[i][1] <= max_w) || (sizes[i][0] <= max_w && sizes[i][1] <= max_h))) {
                if (sizes[i][0] <= sizes[i][1])
                    max_w = sizes[i][0];
                else
                    max_w = sizes[i][1];
            }
        }
    }
    
    // calculate the size of rect
    answer = max_h * max_w;
    
    return answer;
}