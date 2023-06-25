#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    sort(lost.begin(), lost.end());
    
    for (int i = 0; i < lost.size(); i++) {
        if (find(reserve.begin(), reserve.end(), lost[i]) != reserve.end()) {
            answer++;
            reserve.erase(find(reserve.begin(), reserve.end(), lost[i]));
            lost.erase(lost.begin() + i);
            i--;
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (answer >= n || reserve.size() == 0)
            break;
        else if (find(reserve.begin(), reserve.end(), lost[i] - 1) != reserve.end()) {
            answer++;
            reserve.erase(find(reserve.begin(), reserve.end(), lost[i] - 1));
        }
        else if (find(reserve.begin(), reserve.end(), lost[i] + 1) != reserve.end()) {
            answer++;
            reserve.erase(find(reserve.begin(), reserve.end(), lost[i] + 1));
        }
    }
    
    return answer;
}