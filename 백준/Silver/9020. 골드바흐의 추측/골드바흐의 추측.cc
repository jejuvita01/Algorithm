#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else {
        for (int i = 2; i <= n/2; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

void fill_the_vector(vector<int> prime)
{
    for (int i = 0; i < 100001; i++) {
        if (is_prime(i))
            prime.push_back(1);
        else
            prime.push_back(0);
    }
}

int main(void)
{
    int tc;
    vector<int> prime;
    
    cin >> tc;
    
    fill_the_vector(prime);
    
    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;
        int a, b;
        a = 0;
        b = n;
        for (int j = n / 2; j >= 2; j--) {
            if (is_prime(j) && is_prime(n - j)) {
                a = j;
                b = n - j;
                j = 1;
            }
        }
        cout << a << ' ' << b << '\n';
    }
    
    return 0;
}
