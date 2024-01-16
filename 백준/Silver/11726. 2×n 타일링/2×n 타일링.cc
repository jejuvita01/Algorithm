#include <iostream>

using namespace std;


long long fibo(int n)
{
    long long f0 = 1;
    long long f1 = 1;
    long long f2;
    
    if (n == 1)
        return 1;
    
    for (int i = 2; i <= n; i++) {
        f2 = (f0 + f1) % 10007;
        f0 = f1 % 10007;
        f1 = f2 % 10007;
    }
    
    return f2 % 10007;
}

int main(void)
{
    int n;
    
    cin >> n;
    
    cout << fibo(n) << endl;
    
    return 0;
}
