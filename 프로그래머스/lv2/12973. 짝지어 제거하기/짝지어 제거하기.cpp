#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    vector<char> word;

    word.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (*(word.end() - 1) == s[i])
            word.pop_back();
        else
            word.push_back(s[i]);
    }
    
    return word.size() == 0;
}