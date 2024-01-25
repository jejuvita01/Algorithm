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
    
    vector<int> dp(sz, 1);
    for (int i = 0; i < sz - 1; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (arr[j] > arr[i])
                dp[j] = max(dp[i] + 1, dp[j]);
        }
    }
    
    answer = *max_element(dp.begin(), dp.end());
    
    cout << answer << endl;
    
    return 0;
}
