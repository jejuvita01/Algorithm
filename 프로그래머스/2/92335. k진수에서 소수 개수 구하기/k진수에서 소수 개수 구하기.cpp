#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(long long n) {    
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (long long i = 2; i <= sqrt(n); i++) 
        if (n %i == 0)
            return false;
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num = "";
    string temp = "";
    
    while (n > 0) {
        num += to_string(n % k);
        n /= k;
    }
    
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '0') {
            if (temp != "") {
                reverse(temp.begin(), temp.end());
                    if (is_prime(stol(temp)))
                        answer++;
            }
            temp = "";
        }
        else
            temp += num[i];
    }
    if (temp != "") {
        reverse(temp.begin(), temp.end());
        if (is_prime(stol(temp)))
            answer++;
    }
    
    return answer;
}