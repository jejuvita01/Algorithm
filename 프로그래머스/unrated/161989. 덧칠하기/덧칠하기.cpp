#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int index = 0;
    int location = 0;
    
    sort(section.begin(), section.end());
    
    // paint the first section
    location = section[index];
    answer++;
    index++;
    while (index < section.size()) {
        if (location + m - 1 >= section[index]) 
            index++;
        else {
            location = section[index];
            answer++;
            index++;
        }
    }
    
    return answer;
}