#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    
    for (int i = 0; i < s.length(); i++)
        answer.push_back(s[i] - '0');
    reverse(answer.begin(), answer.end());
    
    return answer;
}