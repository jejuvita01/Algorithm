#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int size = priorities.size();
    
    while (1) {
        cout << "priorities[0]: " << priorities[0] << ", ";
        if (priorities[0] >= *max_element(priorities.begin(), priorities.end())) {
            if (location == 0)
                break;
            else {
                cout << "biggest and not location" << endl;
                priorities.erase(priorities.begin());
                location--;
                answer++;
            }
        }
        else {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            if (location == 0) {
                location = priorities.size() - 1;
                cout << "not the biggest, and location" << endl;
            }
            else {
                location--;
                cout << "not the biggest, and not location" << endl;
            }
        }
    }
    
    return answer;
}