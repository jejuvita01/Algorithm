#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l, r;
    int l_dist, r_dist;
    
    l = 10;
    r = 12;
    for (int i = 0; i < numbers.size(); i++) {
        switch (numbers[i]) {
            case 1: case 4: case 7:
                answer += 'L'; 
                l = numbers[i];
                break;
            case 3: case 6: case 9:
                answer += 'R';
                r = numbers[i];
                break;
            case 2: case 5: case 8: case 0:
                if (numbers[i] == 0) {
                    numbers[i] = 11;
                }
                // get the l_dist
                if (l == 1 || l == 4 || l == 7 || l == 10) {
                    l_dist = (l + 1) - numbers[i] > 0 ? (l + 1) - numbers[i] : numbers[i] - (l + 1);
                    l_dist /= 3;
                    l_dist += 1;
                }
                else {
                    l_dist = l - numbers[i] > 0 ? l - numbers[i] : numbers[i] - l;
                    l_dist /= 3;
                }
                // get the r_dist
                if (r == 3 || r == 6 || r == 9 || r == 12) {
                    r_dist = (r - 1) - numbers[i] > 0 ? (r - 1) - numbers[i] : numbers[i] - (r - 1);
                    r_dist /= 3;
                    r_dist++;
                }
                else {
                    r_dist = r - numbers[i] > 0 ? r - numbers[i] : numbers[i] - r;
                    r_dist /= 3;
                }
                if (l_dist == r_dist) {
                    if (hand == "left") {
                        answer += 'L';
                        l = numbers[i];
                    }
                    else {
                        answer += 'R';
                        r = numbers[i];
                    }
                }
                else if (l_dist > r_dist) {
                    answer += 'R';
                    r = numbers[i];
                }
                else {
                    answer += 'L';
                    l = numbers[i];
                }
                break;
        }
    }
    
    return answer;
}