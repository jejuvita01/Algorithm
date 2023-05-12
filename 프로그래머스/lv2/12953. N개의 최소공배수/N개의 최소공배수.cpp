#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    for (int i = 0; i < arr.size(); i++) {
        int r = 0;
        int a = answer;
        int b = arr[i];
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        answer = (answer * arr[i]) / a;
    }
    
    return answer;
}