#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int a, b;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    a = b = 0;
    while (a < A.size() && b < B.size()) {
        if (A[a] < B[b]) {
            answer++;
            a++;
            b++;
        }
        else
            b++;
    }
    
    return answer;
}