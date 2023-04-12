#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int complete = 0;
    int temp = 0;
    int index = 0;
    int minus = 0;
    
    for (int i = 0; i < progresses.size(); i++) 
        progresses[i] = ceil((100 - progresses[i]) / (double)speeds[i]);
    
    while (complete < progresses.size()) {
        minus = progresses[index];
        for (int i = index; i < progresses.size(); i++) {
            progresses[i] -= minus;
            cout << "//i : " << i << ", progresses[i] : " << progresses[i] << endl;
        }
        for (int i = index; i < progresses.size() && progresses[i] <= 0; i++) {
            cout << "index: " << index << endl;
            cout << "i : " << i << ", progresses[i] : " << progresses[i] << endl;
            complete++;
            temp++;
            index++;
        }
        if (temp > 0) {
            answer.push_back(temp);
            temp = 0;
        }
    }
    
    return answer;
}