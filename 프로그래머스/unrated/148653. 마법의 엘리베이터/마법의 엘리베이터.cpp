#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0) {
        if (storey % 10 < 5) 
            answer += storey % 10;
        else if (storey % 10 == 5) {
            if (((storey + 10) / 10) % 10 == 0 || (storey / 10 % 10) == 5) {
                answer += 5;
                storey += 10;
            }
            else
                answer += storey % 10;
        }
        else {
            answer += (10 - storey % 10);
            storey += 10;
        }
        // cout << "answer: " << answer << ", storey: " << storey << endl;
        storey /= 10;
    }
    
    return answer;
}