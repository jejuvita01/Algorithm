#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int total = 0;
    
    for (int i = 0; i < number.size(); i++)
        total += number[i];
    
    for (int i = 0; i < discount.size() - 10 + 1; i++) {
        map<string, int> want_num;
        int remain = total;
        for (int j = 0; j < want.size(); j++) 
            want_num.insert(make_pair(want[j], number[j]));
        for (int k = 0; k < 10; k++) {
            if (want_num.find(discount[i + k]) != want_num.end()) {
                if (want_num[discount[i + k]] > 0) {
                    want_num[discount[i + k]]--;
                    remain--;
                }
            }
        }
        if (remain == 0) {
            // cout << i << endl;
            answer++;
        }
    }
    
    return answer;
}