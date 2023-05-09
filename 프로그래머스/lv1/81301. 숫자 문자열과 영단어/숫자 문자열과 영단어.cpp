#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer = "";
    
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9')
            answer += s[i];
        else {
            switch (s[i]) {
                case 'z': // zero -> 0
                    answer += '0';
                    i += 4 - 1;
                    break;
                case 'o': // one -> 1
                    answer += '1';
                    i += 3 - 1;
                    break;
                case 't': // two -> 2, three -> 3
                    if (s[i + 1] == 'w') {
                        answer += '2';
                        i += 3 - 1;
                    }
                    else {
                        answer += '3';
                        i += 5 - 1;
                    }
                    break;
                case 'f': // four -> 4, five -> 5
                    if (s[i + 1] == 'o') {
                        answer += '4';
                        i += 4 - 1;
                    }
                    else {
                        answer += '5';
                        i += 4 - 1;
                    }
                    break;
                case 's': // six -> 6, seven -> 7
                    if (s[i + 1] == 'i') {
                        answer += '6';
                        i += 3 - 1;
                    }
                    else {
                        answer += '7';
                        i += 5 - 1;
                    }
                    break;
                case 'e': // eight -> 8
                    answer += '8';
                    i += 5 - 1;
                    break;
                case 'n': // nine -> 9
                    answer += '9';
                    i += 4 - 1;
                    break;
                default:
                    break;
            }
        }
    }
    
    return stoi(answer);
}