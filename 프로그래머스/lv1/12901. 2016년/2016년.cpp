#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day_name = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int day = 5;
    
    for (int i = 1; i < a; i++) {
        switch (i) {
            case 2:
                day += 29; cout << "29" << endl; break;
            case 4: case 6: case 9: case 11:
                day += 30; cout << "30" << endl; break;
            default:
                day += 31; cout << "31" << endl; break;
        }
    }
    
    day += b - 1;
    
    answer = day_name[day % 7];
    
    return answer;
}