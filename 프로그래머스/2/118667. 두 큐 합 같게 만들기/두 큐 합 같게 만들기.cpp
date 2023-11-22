#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0; // to save the sum of queue1
    long long sum2 = 0; // to save the sum of queue2
    int i = 0; // index for queue1
    int j = 0; // index for queue2
    int max_try = queue1.size() * 3;
    
    sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    
    if ((sum1 + sum2) % 2 != 0) // queues cannot be same
        return -1;
    
    while (answer < max_try) {
        if (sum1 > sum2) { 
            sum1 -= queue1[i];
            sum2 += queue1[i];
            queue2.push_back(queue1[i++]);
            answer++;
        }
        else if (sum1 < sum2) {
            sum1 += queue2[j];
            sum2 -= queue2[j];
            queue1.push_back(queue2[j++]);
            answer++;
        }
        else // sum1 == sum2
            return answer;
        
        if (i >= queue1.size() || j >= queue2.size())
            return -1;
    }
    if (sum1 != sum2)
        return -1;
    
    return answer;
}