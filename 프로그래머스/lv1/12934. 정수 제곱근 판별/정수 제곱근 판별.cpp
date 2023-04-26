#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    if ((long long)sqrt(n) * (long long)sqrt(n) == n)
        answer = ((long long)sqrt(n) + 1) * ((long long)sqrt(n) + 1);
    else
        answer = -1;
    
    return answer;
}