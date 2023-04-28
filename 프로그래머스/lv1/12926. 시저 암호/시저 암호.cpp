#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            answer += s[i];
        else {
            if ('a' <= s[i] && s[i] <= 'z') {
                if (s[i] + n > 'z') {
                    s[i] -= 26;
                }
            }
            else if ('A' <= s[i] && s[i] <= 'Z') {
                if (s[i] + n > 'Z') {
                    s[i] -= 26;
                }
            }
            answer += s[i] + n;
        }
    }
    
    return answer;
}