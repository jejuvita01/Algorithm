#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> req_time;
vector<int> money;
int dp[15] = {0, }; // 번 돈을 저장
int answer = 0;

void DP(void)
{
    for (int i = 0; i <= n; i++) {
        dp[i] = max(dp[i], answer);
        if (i + req_time[i] <= n)
            dp[i + req_time[i]] = max(dp[i + req_time[i]], dp[i] + money[i]);
        answer = max(answer, dp[i]);
    }
}

int main(void)
{
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int t, m;
        cin >> t >> m;
        req_time.push_back(t);
        money.push_back(m);
    }
    
    DP();
    cout << answer << '\n';
    
    return 0;
}
