#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string tmp;
    int three = 1;
    
    while (n > 0) {
        tmp += (n % 3 + '0');
        n /= 3;
    }
    for (int i = tmp.length() - 1; i >= 0; i--) {
        answer += three * (tmp[i] - '0');
        three *= 3;
    }
    
    return answer;
}