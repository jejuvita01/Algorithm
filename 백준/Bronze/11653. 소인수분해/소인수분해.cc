#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    vector<int> div;
    int d = 2;
    
    cin >> n;
    
    while (n > 1) {
        if (n % d == 0) {
            cout << d << '\n';
            n /= d;
        }
        else
            d++;
    }
    
    return 0;
}
