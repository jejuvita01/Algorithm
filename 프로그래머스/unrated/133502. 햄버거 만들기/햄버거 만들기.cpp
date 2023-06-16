#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> burger;
    
    for (int i = 0; i < ingredient.size(); i++) {
        burger.push_back(ingredient[i]);
        if (burger.size() >= 4) {
            if (*(burger.end() - 1) == 1 && *(burger.end() - 2) == 3 && *(burger.end() - 3) == 2 && *(burger.end() - 4) == 1) {
                answer++;
                burger.erase(burger.end() - 4, burger.end());
            }
        }
    }
    
    return answer;
}