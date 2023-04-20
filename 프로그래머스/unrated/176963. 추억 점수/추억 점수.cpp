#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> name_year;
    int tmp = 0;
    
    for (int i = 0; i < name.size(); i++)
        name_year[name[i]] = yearning[i];
    
    for (int i = 0; i < photo.size(); i++) {
        tmp = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            // cout << photo[i][j] << endl;
            // cout << name_year[photo[i][j]] << endl;
            tmp += name_year[photo[i][j]];
        }
        // cout << tmp << endl;
        answer.push_back(tmp);
    }
    
    return answer;
}