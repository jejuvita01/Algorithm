#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> bracket;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            bracket.push_back('(');
        else if (s[i] == ')') {
            if (bracket.size() == 0)
                return false;
            else
                bracket.pop_back();
        }
    }
    if (bracket.size())
        answer = false;

    return answer;
}