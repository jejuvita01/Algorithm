#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int n; // how many num?
vector<double> num; // vector of numbers
int freq[8001] = {0};

int get_mean(void)
{
    double sum = 0;
    
    for (int i = 0; i < n; i++)
        sum += (double)num[i];
    
    sum /= (double)n;
    
    return round(sum) + 0.0;
}

int get_middle(void)
{
    return num[n / 2];
}

int get_freq(void)
{
    int max_freq = 0;
    int min = 5000;
    int second_min = 5000;
    int answer = 0; // 0: min, 1: second_min
    
    for (int i = 0; i <= 8000; i++) {
        if (freq[i] > 0) {
            if (freq[i] > max_freq) {
                min = i - 4000;
                max_freq = freq[i];
                answer = 0;
            }
            else if (freq[i] == max_freq) {
                if (i - 4000 < second_min || freq[second_min + 4000] != max_freq) {
                    second_min = i - 4000;
                    answer = 1;
                }
            }
        }
    }
    
    if (answer == 0)
        return min;
    else
        return second_min;
}

int get_range(void)
{
    return num[n - 1] - num[0];
}

int main(void)
{
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
        freq[x + 4000]++;
    }
    
    sort(num.begin(), num.end());
    
    cout << get_mean() << '\n';
    cout << get_middle() << '\n';
    cout << get_freq() << '\n';
    cout << get_range() << '\n';
    
    return 0;
}
