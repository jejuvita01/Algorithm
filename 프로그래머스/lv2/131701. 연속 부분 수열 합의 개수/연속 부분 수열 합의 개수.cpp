#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    vector<int> num;
    
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++) {
            sum += elements[(i + j) % size];
            num.push_back(sum);
        }
    }
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    answer = num.size();
    
    return answer;
}