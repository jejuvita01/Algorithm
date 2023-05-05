#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    unsigned long long t_num, p_num;
    
    for (int i = 0; i < t.length() - p.length() + 1; i++) {
        string tmp = "";
        for (int j = 0; j < p.length(); j++) 
            tmp += t[i + j];
        t_num = stoll(tmp);
        p_num = stoll(p);
        if (t_num <= p_num)
            answer++;
    }
    
    return answer;
}