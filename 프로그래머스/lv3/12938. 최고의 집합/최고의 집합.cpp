#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s - n < 0)
        answer.push_back(-1);
    else {
        int minus = floor(s / n);
        while (minus * s != n && n > 1) {
            answer.push_back(minus);
            s -= minus;
            n--;
            minus = floor(s / n);
        }
        answer.push_back(s);
    }
    
    return answer;
}