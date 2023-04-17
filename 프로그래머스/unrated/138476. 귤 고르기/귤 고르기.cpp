#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int tmp = 1;
    vector<int> repeat;
    
    sort(tangerine.begin(), tangerine.end());
    for (int i = 0; i < tangerine.size() - 1; i++) {
        if (tangerine[i] == tangerine[i + 1])
            tmp++;
        else {
            repeat.push_back(tmp);
            tmp = 1;
        }
    }
    repeat.push_back(tmp);
    
    sort(repeat.begin(), repeat.end());
    int index = repeat.size() - 1;
    while (k > 0) {
        k -= repeat[index--];
        answer++;
    }
    
    return answer;
}