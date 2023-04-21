#include <string>
#include <vector>

using namespace std;

// a : 줘야하는 병 수, b : 받는 병 수, n : 지금 가지고 있는 병 수
int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a) {
        int getting_num = (n / a) * b;
        answer += getting_num;
        n -= (n / a) * a;
        n += getting_num;
    }
    // answer += n;
    
    return answer;
}