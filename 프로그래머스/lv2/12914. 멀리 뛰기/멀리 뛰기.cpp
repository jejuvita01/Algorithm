#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer; // gonna be used as f2
    long long f0 = 0;
    long long f1 = 1;
    
    for (int i = 0; i < n; i++) {
        answer = (f0 + f1) % 1234567;
        f0 = f1 % 1234567;
        f1 = answer % 1234567;
    }
    
    return answer;
}