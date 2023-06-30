#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> small; // ascending order
    priority_queue<int, vector<int>, less<int>> big; // descending order
    int total_plus;
    int big_minus, small_minus;
    
    total_plus = big_minus = small_minus = 0;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            int num = 0;
            bool minus_flag = false;
            string tmp = "";
            for (int j = 2; j < operations[i].length(); j++) {
                if (j == 2 && operations[i][j] == '-')
                    minus_flag = true;
                else
                    tmp += operations[i][j];
            }
            if (minus_flag)
                num = (-1) * (stoi(tmp));
            else
                num = stoi(tmp);
            small.push(num);
            big.push(num);
            total_plus++;
        }
        else if (operations[i] == "D 1") {
            if (!big.empty()) {
                big.pop(); // biggest
                big_minus++;
            }
        }
        else {
            if (!small.empty()) {
                small.pop(); // smallest
                small_minus++;
            }
        }
    }
    vector<int> total;
    vector<int> same;
    if (total_plus - big_minus - small_minus <= 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        while (!small.empty()) {
            total.push_back(small.top());
            small.pop();
        }
        while (!big.empty()) {
            total.push_back(big.top());
            big.pop();
        }
        sort(total.begin(), total.end());
        for (int i = 0; i < total.size() - 1; i++)
            if (total[i] == total[i + 1])
                same.push_back(total[i]);
        sort(same.begin(), same.end());            
        answer.push_back(same[same.size() - 1]);
        answer.push_back(same[0]);
        //answer.push_back(big.top());
        //answer.push_back(small.top());
    }
    
    
    return answer;
}