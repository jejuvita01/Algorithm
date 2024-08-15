#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    long long n, x;
    
    scanf("%lld", &n);
    
    priority_queue<long long, vector<long long>, greater<long long>> num;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &x);
            if (i == 0)
                num.push(x);
            else {
                if (num.top() < x) {
                    num.pop();
                    num.push(x);
                }
            }
        }
    }
    
    printf("%lld\n", num.top());
    
    return 0;
}
