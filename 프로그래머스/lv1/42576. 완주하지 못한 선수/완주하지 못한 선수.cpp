#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int part_index = 0;
    int comp_index = 0;
    int comp_num = completion.size();
    int answer_index;
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    while (comp_index < comp_num) {
        if (participant[part_index] != completion[comp_index]) {
            answer_index = part_index;
            break;
        }
        else {
            part_index++;
            comp_index++;
        }
    }
    
    answer = participant[answer_index];
        
    return answer;
}