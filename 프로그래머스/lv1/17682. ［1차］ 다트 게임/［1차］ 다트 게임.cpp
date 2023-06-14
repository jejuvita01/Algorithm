#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int prev_score = -10000;
    int score;
    
    for (int i = 0; i < dartResult.length(); i++) {
        if (isdigit(dartResult[i])) {
            if (isdigit(dartResult[i + 1])) {
                score = 10;
                i++;
            }
            else
                score = dartResult[i] - '0';
        }
        else if (isalpha(dartResult[i])) {
            switch (dartResult[i]) {
                case 'D':
                    score = score * score;
                    break;
                case 'T':
                    score = score * score * score;
                    break;
                default:
                    break;
            }
            if (i == dartResult.length() - 1 || isdigit(dartResult[i + 1])) {
                answer += score;
                // cout << "answer: " << answer << ", score: " << score << endl;
                prev_score = score;
                score = 0;
            }
        }
        else {
            if (dartResult[i] == '*') {
                if (prev_score == -10000) {
                    answer += score * 2;
                    // cout << "answer: " << answer << ", score: " << score << endl;
                    prev_score = score * 2;
                    score = 0;
                }
                else {
                    answer -= prev_score;
                    // cout << "answer: " << answer << ", score: " << score << endl;
                    answer += prev_score * 2;
                    answer += score * 2;
                    prev_score = score * 2;
                    score = 0;
                }
            }
            else if (dartResult[i] == '#') {
                answer += (-1) * score;
                // cout << "answer: " << answer << ", score: " << score << endl;
                prev_score = (-1) * score;
                score = 0;
            }
        }
    }
    
    return answer;
}