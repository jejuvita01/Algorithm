#include <iostream>

using namespace std;

int main(void)
{
    long long a, b, c;
    long long answer = 1;
    
    cin >> a >> b >> c;
    
    while (b > 0) {
        a %= c;
        if (b % 2 != 0)
            answer *= a;
        a *= a;
        answer %= c;
        b /= 2;
    }
    
    cout << answer << endl;
    
    return 0;
}
