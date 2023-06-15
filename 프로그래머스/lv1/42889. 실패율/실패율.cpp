#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    return (a.second != b.second ? a.second > b.second : a.first < b.first);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int stage_num = stages.size();
    map<int, double> stage_fail;
    int current_stage = 0;
    int fail_num = 0;
    vector<pair<int, double>> map_to_vec;
    
    sort(stages.begin(), stages.end());
    
    for (int i = 0; i < stage_num; i++) {
        if (current_stage == 0) {
            current_stage = stages[i];
            fail_num++;
        }
        else if (current_stage != stages[i]) {
            stage_fail.insert(make_pair(current_stage, (double)fail_num / (stage_num - i + fail_num)));
            cout << current_stage << ": " << (double)fail_num / (stage_num - i + fail_num) << endl;
            current_stage = stages[i];
            fail_num = 1;
        }
        else
            fail_num++;
    }
    cout << current_stage << ": " << double(fail_num) / (fail_num) << endl;
    if (current_stage <= N)
        stage_fail.insert(make_pair(current_stage, (double)fail_num / (fail_num)));
    
    for (int i = 1; i <= N; i++) {
        if (stage_fail.find(i) == stage_fail.end())
            stage_fail.insert(make_pair(i, 0.0));
        map_to_vec.push_back(make_pair(i, stage_fail[i]));
    }
    
    for (int i = 0; i < map_to_vec.size(); i++) {
        cout << "key: " << map_to_vec[i].first << ", val: " << map_to_vec[i].second << endl;
    }
    
    sort(map_to_vec.begin(), map_to_vec.end(), compare);
    
    for (int i = 0; i < N; i++) 
        answer.push_back(map_to_vec[i].first);
    
    return answer;
}