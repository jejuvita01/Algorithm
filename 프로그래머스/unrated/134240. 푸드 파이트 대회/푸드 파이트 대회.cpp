#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string rvs = "";
    
    for (int i = 1; i < food.size(); i++) {
        for (int j = 1; j <= food[i] / 2; j++)
            answer += (i + '0');
    }
    rvs = answer;
    reverse(rvs.begin(), rvs.end());
    answer += '0';
    answer += rvs;
    
    return answer;
}