#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> skip_char;
    
    // make skip_char vector 
    for (int i = 0; i < skip.length(); i++) 
        skip_char.push_back(skip[i]);
    
    // sort skip_char vector
    sort(skip_char.begin(), skip_char.end());
    
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= index; j++) {
            s[i]++;
            if (s[i] > 'z')
                s[i] -= ('z' - 'a' + 1);
            while (find(skip_char.begin(), skip_char.end(), s[i]) != skip_char.end()) {
                s[i]++;
                if (s[i] > 'z')
                    s[i] -= ('z' - 'a' + 1);
            }
        }
        answer += s[i];
    }
    
    
    return answer;
}