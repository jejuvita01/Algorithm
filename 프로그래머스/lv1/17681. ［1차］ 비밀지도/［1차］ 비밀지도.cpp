#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> arr1_str;
    vector<string> arr2_str;
    
    // change number to string
    for (int i = 0; i < arr1.size(); i++) {
        string tmp1 = "";
        string tmp2 = "";
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2 == 0)
                tmp1 += ' ';
            else
                tmp1 += '#';
            arr1[i] /= 2;
            if (arr2[i] % 2 == 0)
                tmp2 += ' ';
            else
                tmp2 += '#';
            arr2[i] /= 2;
        }
        reverse(tmp1.begin(), tmp1.end());
        reverse(tmp2.begin(), tmp2.end());
        arr1_str.push_back(tmp1);
        arr2_str.push_back(tmp2);
    }
    
    for (int i = 0; i < arr1_str.size(); i++) {
        string tmp = "";
        for (int j = 0; j < arr1_str[i].length(); j++) {
            if (arr1_str[i][j] == '#' || arr2_str[i][j] == '#')
                tmp += '#';
            else
                tmp += ' ';
        }
        answer.push_back(tmp);
    }
    
    return answer;
}