#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> point(4); // vector to save the points of types
    // R, C, J, A is positive , T, F, M, N is negative
    int type; // RT : 0, CF : 1, JM : 2, AN : 3
    int sign; // case 'TR', 'FC', 'MJ', 'NA', multiply -1 to the point
    
    for (int i = 0; i < survey.size(); i++) {
        if (survey[i] == "RT") {
            type = 0; sign = 1;
        }
        else if (survey[i] == "TR") {
            type = 0; sign = -1;
        }
        else if (survey[i] == "CF") {
            type = 1; sign = 1;
        }
        else if (survey[i] == "FC") {
            type = 1; sign = -1;
        }
        else if (survey[i] == "JM") {
            type = 2; sign = 1;
        }
        else if (survey[i] == "MJ") {
            type = 2; sign = -1;
        }
        else if (survey[i] == "AN") {
            type = 3; sign = 1;
        }
        else if (survey[i] == "NA") {
            type = 3; sign = -1;
        }

        switch (choices[i]) {
            case 1: point[type] += sign * 3; break;
            case 2: point[type] += sign * 2; break;
            case 3: point[type] += sign * 1; break;
            case 5: point[type] -= sign * 1; break;
            case 6: point[type] -= sign * 2; break;
            case 7: point[type] -= sign * 3; break;
        }
    }
    
    if (point[0] >= 0)
        answer += "R";
    else
        answer += "T";
    if (point[1] >= 0)
        answer += "C";
    else
        answer += "F";
    if (point[2] >= 0)
        answer += "J";
    else
        answer += "M";
    if (point[3] >= 0)
        answer += "A";
    else
        answer += "N";
    
    return answer;
}