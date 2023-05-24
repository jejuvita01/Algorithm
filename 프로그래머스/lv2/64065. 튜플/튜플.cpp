#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return (a.size() < b.size());
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> num(100000);
    int index = -1;
    string tmp = "";
    
    s.erase(s.begin());
    s.erase(s.end() - 1);
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{')
            index++;
        else if (s[i] == ',') {
            if (tmp != "")
                num[index].push_back(stoi(tmp));
            tmp = "";
        }
        else if (s[i] == '}') {
            if (tmp != "")
                num[index].push_back(stoi(tmp));
            tmp = "";
        }
        else 
            tmp += s[i];
    }
    
    sort(num.begin(), num.begin() + index + 1, compare);
    
    for (int i = 0; i < index + 1; i++) {
        for (int j = 0; j < num[i].size(); j++) 
            if (find(answer.begin(), answer.end(), num[i][j]) == answer.end())
                answer.push_back(num[i][j]);
    }
    
    return answer;
}