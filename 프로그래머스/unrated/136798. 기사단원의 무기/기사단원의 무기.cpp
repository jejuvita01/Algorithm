#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int div;
    
    for (int i = 1; i <= number; i++) {
        div = 1;
        int j;
        for (j = 2; j * j < i; j++) {
            if (i % j == 0)
                div++;
        }
        if (i != 1) {
            if (j * j == i)
                div = (div * 2) + 1;
            else
                div *= 2;
        }
        // cout << i << ':' << div << endl;
        if (div > limit)
            answer += power;
        else
            answer += div;
    }
    
    return answer;
}