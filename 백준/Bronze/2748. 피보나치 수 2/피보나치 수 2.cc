#include <iostream>

using namespace std;

int main(void)
{
    int n;
    long long f0 = 0;
    long long f1 = 1;
    long long f2 = f0 + f1;
    
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    if (n == 0)
        f2 = f0;
    else if (n == 1)
        f2 = f1;
    
    printf("%lld\n", f2);
    
    return 0;
}
