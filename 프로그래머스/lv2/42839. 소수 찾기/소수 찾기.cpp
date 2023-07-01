#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(char a, char b) 
{
    return (a > b);
}

bool is_inside(string num, string tmp) 
{
    int num_index, tmp_index;
    int same_num = 0;
    
    sort(num.begin(), num.end());
    sort(tmp.begin(), tmp.end());
    
    num_index = tmp_index = 0;
    while (num_index < num.length() && tmp_index < tmp.length()) {
        if (num[num_index] > tmp[tmp_index]) {
            num_index++;
        }
        else if (num[num_index] < tmp[tmp_index]) {
            num_index++;
        }
        else {
            same_num++;
            num_index++;
            tmp_index++;
        }
    }
    
    return (same_num == tmp.size());
}

int solution(string numbers) {
    int answer = 0;
    string max = "";
    string min = "";
    
    // sort as descending order
    sort(numbers.begin(), numbers.end(), comp);
        
    // get max and min
    max = numbers;
    for (int i = numbers.length() - 1; i >= 0; i--)
        if (numbers[i] != '0') {
            min += numbers[i];
            break;
        }
    
    // look up all numbers from min to max
    // and count prime numbers
    for (int i = stoi(min); i <= stoi(max); i++) {
        string tmp = to_string(i);
        sort(tmp.begin(), tmp.end());
        // cout << tmp << ", inside? : " << is_inside(numbers, tmp) << endl;
        if (is_inside(numbers, tmp)) {
            bool is_prime_num = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    is_prime_num = false;
                    break;
                }
            }
            if (is_prime_num && i != 1) {
                answer++;
                // cout << '*' << tmp << ", " << i << endl;
            }
        }
    }
    
    return answer;
}