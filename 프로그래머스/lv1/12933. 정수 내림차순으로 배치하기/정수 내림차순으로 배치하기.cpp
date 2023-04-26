#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string num = to_string(n);
    
    sort(num.begin(), num.end());
    for (int i = 0; i < num.length(); i++) {
        answer *= 10;
        answer += num[num.length() - 1 - i] - '0';
    }
    
    return answer;
}