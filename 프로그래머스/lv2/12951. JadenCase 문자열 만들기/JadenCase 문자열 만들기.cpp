#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int tmp = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            tmp = 0;
            answer += s[i];
        }
        else {
            if (tmp == 0 && isalpha(s[i]))
                answer += toupper(s[i]);
            else if (tmp != 0 && isalpha(s[i]))
                answer += tolower(s[i]);
            else
                answer += s[i];
            tmp++;
        }
    }
    
    return answer;
}