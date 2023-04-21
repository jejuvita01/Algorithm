#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long f0 = 0;
    long long f1 = 1;
    long long f2 = f0 + f1;
    
    for (long long i = 2; i <= n; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
        f2 %= 1234567;
        f0 %= 1234567;
        f1 %= 1234567;
    }
    answer = f2;
    
    return answer;
}