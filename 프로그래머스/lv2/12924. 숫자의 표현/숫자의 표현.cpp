#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j;
            // cout << j << endl;
            if (sum > n)
                j = n;
            else if (sum == n)
                answer++;
        }
    }
    
    return answer;
}