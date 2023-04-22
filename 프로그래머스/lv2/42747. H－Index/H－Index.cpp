#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int repeat = 1;
    map<int, int> citation_repeat; // <citation num : repeated num>
    
    // make the <citation num : repeated num> map
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size() - 1; i++) {
        if (citations[i] != citations[i + 1]) {
            citation_repeat.insert(make_pair(citations[i], repeat));
            repeat = 1;
        }
        else
            repeat++;
    }
    citation_repeat.insert(make_pair(citations[citations.size() - 1], repeat));
    
    /* // print out the maps
    map<int, int>::iterator it;
    for (it = citation_repeat.begin(); it != citation_repeat.end(); it++) 
        cout << "citation: " << it->first << ", repeat: " << it->second << endl;
    */
    
    // compare keys and values, and get the answer
    map<int, int>::iterator it;
    for (int h = 1; h <= citations[citations.size() - 1]; h++) {
        int sum = 0;
        bool flag = true;
        // get the sum of papers which is cited more or same time with h
        for (it = citation_repeat.begin(); it != citation_repeat.end(); it++)
            if (it->first >= h)
                sum += it->second;
        if (sum >= h) {
            for (it = citation_repeat.begin(); it != citation_repeat.end(); it++)
                if (it->second > h)
                    flag = false;
            if (flag) {
                answer = h;
                // cout << h << endl;
                // break;
            }
        }
    }
    
    return answer;
}