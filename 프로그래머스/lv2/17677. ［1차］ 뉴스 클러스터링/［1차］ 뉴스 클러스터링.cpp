#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> st1;
    vector<string> st2;
    int index_1, index_2;
    int same, sum;
    
    // save elements from strings
    for (int i = 0; i < str1.length() - 1; i++) {
        string tmp = "";
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
            tmp += tolower(str1[i]);
            tmp += tolower(str1[i + 1]);
            st1.push_back(tmp);
            // cout << tmp << endl;
        }
    }
    
    for (int i = 0; i < str2.length() - 1; i++) {
        string tmp = "";
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            tmp += tolower(str2[i]);
            tmp += tolower(str2[i + 1]);
            st2.push_back(tmp);
            // cout << tmp << endl;
        }
    }
    
    // sort those two vectors
    sort(st1.begin(), st1.end());
    sort(st2.begin(), st2.end());
    
    // get same and sum value by merge sort
    index_1 = index_2 = 0;
    same = sum = 0;
    while (index_1 < st1.size() && index_2 < st2.size()) {
        if (st1[index_1] == st2[index_2]) {
            index_1++;
            index_2++;
            same++;
            sum++;
        }
        else if (st1[index_1] > st2[index_2]) {
            index_2++;
            sum++;
        }
        else {
            index_1++;
            sum++;
        }
    }
    // if there's anything left, add it to sum
    sum += (st1.size() - index_1) + (st2.size() - index_2);
    // cout << same << ' ' << sum << endl;
    
    // get the answer
    if (same == 0 && sum == 0)
        answer = 65536;
    else
        answer = (int)(65536 * (same / (double)sum));
    
    return answer;
}