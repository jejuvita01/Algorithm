#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long f0 = 0;
    long long f1 = 1;
    long long f2 = f0 + f1;
    
    for (int i = 0; i < n; i++) {
        f2 = (f0 + f1) % 1000000007;
        f0 = f1 % 1000000007;
        f1 = f2 % 1000000007;
    }
    
    answer = f2;
    return answer;
}