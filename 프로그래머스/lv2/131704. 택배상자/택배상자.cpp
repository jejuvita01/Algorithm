#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> assist;
    int box_num = 1;
    
    for (int i = 0; i < order.size(); i++) {
        while (box_num <= order.size() && box_num <= order[i])
            assist.push(box_num++);
        if (box_num == order[i]) {
            answer++;
            // cout << box_num << endl;
        }
        else {
            if (assist.top() == order[i]) {
                answer++;
                // cout << assist.top() << endl;
                assist.pop();
            }
            else
                break;
        }
    }
    
    return answer;
}