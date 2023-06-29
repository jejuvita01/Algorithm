#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> num;
    
    for (int i = 0; i < scoville.size(); i++)
        num.push(scoville[i]);
    
    while (num.top() < K && num.size() > 1) {
        int first = num.top();
        num.pop();
        int second = num.top();
        num.pop();
        num.push(first + (second * 2));
        answer++;
        if (answer > scoville.size())
            break;
    }
    if (num.top() < K)
        answer = -1;
    
    return answer;
}