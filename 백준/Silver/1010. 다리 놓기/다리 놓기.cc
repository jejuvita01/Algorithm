#include <iostream>

using namespace std;

int main(void)
{
    int tc;
    long long int n, m;
    long long int answer;
    
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n >> m;
        // mCn
        answer = 1;
        if (n > m / 2)
            n = m - n;
        for (long long int j = 1; j <= n; j++)
            answer *= (m - (j - 1));
        // cout << answer << endl;
        for (long long int j = 1; j <= n; j++)
            answer /= j;
        cout << answer << endl;
    }
    
    return 0;
}
