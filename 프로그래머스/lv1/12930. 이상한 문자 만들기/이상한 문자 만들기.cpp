#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int tmp = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += s[i];
            tmp = 0;
        }
        else {
            if (tmp % 2 == 0)
                answer += toupper(s[i]);
            else
                answer += tolower(s[i]);
            tmp++;
        }
    }
    
    return answer;
}