#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> score(4, 0); // saving score of each type
    
    for (int i = 0; i < survey.size(); i++) {
        int mul = 1; // if the string isn't sequential, change mul to -1
        int score_index = 0; // 0:RT, 1:CF, 2:JM, 3:AN
        switch (survey[i][0]) { // change score_index value
            case 'R': case 'T': score_index = 0; break;
            case 'C': case 'F': score_index = 1; break;
            case 'J': case 'M': score_index = 2; break;
            case 'A': case 'N': score_index = 3; break;
            default: break;
        }
        if (survey[i][0] > survey[i][1]) // change mul value if needed
            mul = -1;
        switch (choices[i]) {
            case 1: score[score_index] += mul * 3; break;
            case 2: score[score_index] += mul * 2; break;
            case 3: score[score_index] += mul * 1; break;
            case 5: score[score_index] -= mul * 1; break;
            case 6: score[score_index] -= mul * 2; break;
            case 7: score[score_index] -= mul * 3; break;
            default: break;
        }
    }
    
    for (int i = 0; i < score.size(); i++) {
        switch (i) {
            case 0: score[i] >= 0 ? answer += 'R' : answer += 'T'; break;
            case 1: score[i] >= 0 ? answer += 'C' : answer += 'F'; break;
            case 2: score[i] >= 0 ? answer += 'J' : answer += 'M'; break;
            case 3: score[i] >= 0 ? answer += 'A' : answer += 'N'; break;
            default: break;
        }
    }
    
    return answer;
}