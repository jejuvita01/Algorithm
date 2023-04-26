#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int n;
    int convert_num;
    int erase_num;
    
    convert_num = erase_num = 0;
    while (s != "1") {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                s.erase(i, 1);
                i--;
                erase_num++;
            }
        }
        n = s.length();
        s.clear();
        while (n > 0) {
            s.push_back(n % 2 + '0');
            n /= 2;
        }
        convert_num++;
    }
    
    answer.push_back(convert_num);
    answer.push_back(erase_num);
    
    return answer;
}