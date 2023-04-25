#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int div = 0;
    
    for (int i = left; i <= right; i++) {
        div = 0;
        int j;
        for (j = 1; j * j < i; j++) {
            if (i % j == 0)
                div++; 
        }
        div *= 2;
        if (j * j == i)
            div += 1;
        cout << i << ": " << div << endl;
        if (div % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}