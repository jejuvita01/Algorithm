#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[5] = {1, 2, 3, 4, 5};
    int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int score[3] = {0, };
    int max_score = 0;
    
    // count each person's score
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == p1[(i + 5) % 5])
            score[0]++;
        if (answers[i] == p2[(i + 8) % 8])
            score[1]++;
        if (answers[i] == p3[(i + 10) % 10])
            score[2]++;
    }
    
    for (int i = 0; i < 3; i++)
        if (score[i] > max_score)
            max_score = score[i];
    
    for (int i = 0; i < 3; i++) {
        cout << "score[i] : " << score[i] << endl;
        if (score[i] == max_score)
            answer.push_back(i + 1);
    }
    
    return answer;
}