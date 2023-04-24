#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> kind_num; // kind_of_clothes : num_of_clothes;
    
    // make kind_num map
    kind_num.insert(make_pair(clothes[0][1], 1));
    for (int i = 1; i < clothes.size(); i++) {
        if (kind_num.find(clothes[i][1]) == kind_num.end()) 
            kind_num.insert(make_pair(clothes[i][1], 1));
        else 
            kind_num[clothes[i][1]]++;
    }
    
    // multiply every kind of clothes's number(kind_num[0][1]) + choosing not wearing that kind of clothes(1)
    map<string, int>::iterator it;
    for (it = kind_num.begin(); it != kind_num.end(); it++)
        answer *= (it->second + 1);
    answer -= 1; // excluding the case choosing all 'x' to every elements
    
    
    return answer;
}