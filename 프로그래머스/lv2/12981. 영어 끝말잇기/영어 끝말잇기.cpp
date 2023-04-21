#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> word;
    
    word.insert(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (words[i][0] != words[i - 1][words[i-1].size() - 1] || word.find(words[i]) != word.end()) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        else 
            word.insert(words[i]);
    }
    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}