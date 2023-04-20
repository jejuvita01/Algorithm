#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string n = "";
    vector<int> num;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && n != "") {
            num.push_back(stoi(n));
            n = "";
        }
        else 
            n += s[i];
    }
    num.push_back(stoi(n));
    
    sort(num.begin(), num.end());
    answer += to_string(num[0]);
    answer += " ";
    answer += to_string(num[num.size() - 1]);
    
    return answer;
}