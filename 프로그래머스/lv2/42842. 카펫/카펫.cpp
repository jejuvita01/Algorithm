#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i < brown; i++) {
        for (int j = 1; j <= i; j++) {
            if ((i - 2) * (j - 2) == yellow) {
                if (i * j - yellow == brown) {
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }
    }
    
    return answer;
}