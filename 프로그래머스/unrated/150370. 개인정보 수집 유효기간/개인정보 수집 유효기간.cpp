#include <string>
#include <vector>
#include <map>
#include <iostream>

#define MONTH 12
#define DAY 28

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> today_date;
    vector<vector<int>> privacie_date;
    map<char, int> term;
    string tmp = "";
    
    // make int vector to save today's year, month, date;
    for (int i = 0; i < today.length(); i++) {
        if (today[i] == '.') {
            today_date.push_back(stoi(tmp));
            tmp = "";
        }
        else 
            tmp += today[i];
    }
    today_date.push_back(stoi(tmp));
    // cout << today_date[0] << endl << today_date[1] << endl <<  today_date[2];
    
    
    // make int vector to save today's year, month, date;
    for (int i = 0; i < privacies.size(); i++) {
        vector<int> v1;
        tmp = "";
        privacie_date.push_back(v1);
        for (int j = 0; j < 10; j++) {
            if (privacies[i][j] == '.') {
                privacie_date[i].push_back(stoi(tmp));
                tmp = "";
            }
            else
                tmp += privacies[i][j];
        }
        privacie_date[i].push_back(stoi(tmp));
        // cout << privacie_date[i][0] << endl << privacie_date[i][1] << endl <<  privacie_date[i][2] << endl;
    }
    
    
    // make <char:int> map to save terms information
    for (int i = 0; i < terms.size(); i++) {
        char alpha = terms[i][0];
        terms[i].erase(0, 2);
        int month = stoi(terms[i]);
        term.insert(make_pair(alpha, month));
        // cout << alpha << " " << month << endl;
    }
    
    
    // calculate the date difference and make answer vector
    for (int i = 0; i < privacies.size(); i++) {
        int diff = 0;
        diff += (today_date[0] - privacie_date[i][0]) * (MONTH * DAY); // year diff
        diff += (today_date[1] - privacie_date[i][1]) * (DAY); // month diff
        diff += today_date[2] - privacie_date[i][2]; // day diff
        diff /= DAY; // convert day difference to month difference
        cout << i << ": " << diff << endl;
        if (diff >= term[privacies[i][11]])
            answer.push_back(i + 1);
    }
    
    return answer;
}