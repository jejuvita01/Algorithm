#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return (a > b);
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same_num = 0;
    int unknown_num = 0;
    
    sort(lottos.begin(), lottos.end(), compare);
    sort(win_nums.begin(), win_nums.end(), compare);
    
    for (int i = 0; i < lottos.size(); i++) {
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j])
                same_num++;
        }
        if (lottos[i] == 0)
            unknown_num++;
    }

    answer.push_back(6 - same_num - unknown_num + 1 >= 1 ? 6 - same_num - unknown_num + 1 <= 6 ? 6 - same_num - unknown_num + 1 : 6 : 1);
    answer.push_back(6 - same_num + 1 < 6 ? 6 - same_num + 1 : 6);
    
    return answer;
}