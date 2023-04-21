#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp_n = n;
    int tmp_answer;
    int n_one_num = 0;
    int answer_one_num = 0;
    
    while (tmp_n > 0) {
        if (tmp_n % 2 == 1)
            n_one_num++;
        tmp_n /= 2;
    }
    
    for (answer = n + 1; ; answer++) {
        answer_one_num = 0;
        tmp_answer = answer;
        while (tmp_answer > 0) {
            if (tmp_answer % 2 == 1)
                answer_one_num++;
            tmp_answer /= 2;
        }
        if (answer_one_num == n_one_num)
            break;
    }
    
    return answer;
}