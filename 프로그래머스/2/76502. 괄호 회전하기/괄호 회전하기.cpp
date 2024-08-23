#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp = "";
    
    for (int i = 0; i < s.length(); i++) {
        vector<char> bracket;
        tmp = "";
        tmp.append(s, i, s.length() - i);
        tmp.append(s, 0, i);
        for (int j = 0; j < tmp.length(); j++) {
            if (tmp[j] == '(' || tmp [j] == '[' || tmp[j] == '{') 
                bracket.push_back(tmp[j]);
            else {
                if (bracket.size() != 0) {
                    if (tmp[j] == ')' && bracket.back() == '(')
                        bracket.pop_back();
                    else if (tmp[j] == ']' && bracket.back() == '[')
                        bracket.pop_back();
                    else if (tmp[j] == '}' && bracket.back() == '{')
                        bracket.pop_back();
                }
                else {
                    if (tmp[j] == ')' || tmp[j] == ']' || tmp[j] == '}')
                        bracket.push_back(tmp[j]);
                }
            }
        }
        if (bracket.size() == 0)
            answer++;
    }
    
    return answer;
}