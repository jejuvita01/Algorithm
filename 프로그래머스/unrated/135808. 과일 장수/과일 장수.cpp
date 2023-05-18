#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    for (int i = 1; i <= score.size() / m; i++) {
        answer += score[score.size() - i * m] * m;
    }
    
    return answer;
}