#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int sz;
    int x;
    vector<int> arr;
    int answer = 0;
    
    cin >> sz;
    for (int i = 0; i < sz; i++) {
        cin >> x;
        arr.push_back(x);
    }
    
    vector<int> dp_up(sz, 1);
    for (int i = 0; i < sz - 1; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (arr[j] > arr[i])
                dp_up[j] = max(dp_up[i] + 1, dp_up[j]);
        }
    }
    
    vector<int> dp_down(sz, 1);
    for (int i = sz - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i])
                dp_down[j] = max(dp_down[i] + 1, dp_down[j]);
        }
    }
    
    vector<int> dp(sz, 0);
    for (int i = 0; i < sz; i++)
        dp[i] = dp_up[i] + dp_down[i] - 1;
    
    answer = *max_element(dp.begin(), dp.end());
    
    cout << answer << endl;
    
    return 0;
}
