#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    else {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

int main(void)
{
    int a, b;
    
    cin >> a >> b;
    
    for (int i = a; i <= b; i++) {
        if (is_prime(i))
            cout << i << '\n';
    }
    
    return 0;
}
