#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int use = 0;
    
    for (int i = 0; i < goal.size(); i++) {
        if (*cards1.begin() == goal[i]) {
            cards1.erase(cards1.begin());
            use++;
        }
        else if (*cards2.begin() == goal[i]) {
            cards2.erase(cards2.begin());
            use++;
        }
        else {
            answer = "No";
            break;
        }
    }
    if (use == goal.size())
        answer = "Yes";
    else
        answer = "No";
    
    return answer;
}