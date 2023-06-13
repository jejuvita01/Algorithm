#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(int a, int b) {
    return (a > b);
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honor;
    
    for (int i = 0; i < score.size(); i++) {
        honor.push_back(score[i]);
        sort(honor.begin(), honor.end(), condition);
        if (honor.size() < k) 
            answer.push_back(honor[honor.size() - 1]);
        else
            answer.push_back(*(honor.begin() + k - 1));
    }
    
    return answer;
}