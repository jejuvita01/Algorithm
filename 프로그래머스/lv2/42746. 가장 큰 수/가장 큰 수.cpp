#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    int index = 0;
    
    while (a.length() < 4) 
        a += a[index++];
    
    index = 0;
    while (b.length() < 4)
        b += b[index++];
    
    return (a < b);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    
    for (int i = 0; i < numbers.size(); i++) {
        string tmp = to_string(numbers[i]);
        // reverse(tmp.begin(), tmp.end());
        num.push_back(tmp);
    }
    
    sort(num.begin(), num.end(), comp);
    
    for (int i = num.size() - 1; i >= 0; i--)
        answer += num[i];
    
    while (answer[0] == '0' && answer.length() > 1) {
        answer.erase(answer.begin());
    }
    
    return answer;
}