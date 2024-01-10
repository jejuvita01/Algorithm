#include <iostream>
#include <vector>

using namespace std;

#define SZ 40

vector<vector<int>> dp(SZ + 1, vector<int>(2, 0));


void fibo(int n)
{
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    if (n != 0 && n != 1) {
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
            dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
        }
    }
    
    return;
}

int main(void)
{
    int tc;
    int n;
    
    
    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        cin >> n;
        fibo(n);
        cout << dp[n][0] << ' ' << dp[n][1] << endl;
    }
    
    return 0;
}
