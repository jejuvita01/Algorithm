#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long b = d;
    
    for (long long a = 0; a <= d; a += k) { // loop for x value
        answer += floor(sqrt((b * b - a * a))) / k + 1;
    }
    
    return answer;
}