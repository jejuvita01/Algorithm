#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    answer.push_back(-1);
    for (int i = 1; i < s.length(); i++) {
        bool inserted_flag = false;
        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == s[i]) {
                // cout << s[j] << endl;
                answer.push_back(i - j);
                inserted_flag = true;
                break;
            }
        }
        if (inserted_flag == false)
            answer.push_back(-1);
    }
    
    return answer;
}