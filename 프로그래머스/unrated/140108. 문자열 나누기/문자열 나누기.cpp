#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    char start = s[0];
    int same = 1;
    int diff = 0;
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == start)
            same++;
        else
            diff++;
        if (same == diff) {
            start = s[i + 1];
            answer++;
            same = 0;
            diff = 0;
            cout << start << endl;
        }
    }
    if (!(same == 0 && diff == 0))
        answer++;
    
    return answer;
}