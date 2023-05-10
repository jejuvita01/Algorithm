#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    if (((a - b) == 1 && a % 2 == 0) || ((b - a) == 1 && b % 2 == 0))
        return 1;
    
    if (a % 2 != 0) // change a to even number
        a += 1;
    if (b % 2 != 0) // change b to even number
        b += 1;
    
    while (!(((a - b) == 1 && a % 2 == 0) || ((b - a) == 1 && b % 2 == 0))) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }
    
    return answer;
}