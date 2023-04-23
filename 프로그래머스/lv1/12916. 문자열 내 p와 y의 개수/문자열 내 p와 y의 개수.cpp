#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (tolower(s[i]) == 'p')
            count++;
        else if (tolower(s[i]) == 'y')
            count--;
    }
    
    answer = (count == 0);
    return answer;
}