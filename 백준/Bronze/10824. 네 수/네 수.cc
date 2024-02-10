#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string a, b, c, d;
    string ab, cd;
    
    cin >> a >> b >> c >> d;
    
    ab = a + b;
    cd = c + d;
    
    cout << stol(ab) + stol(cd) << '\n';
    
    return 0;
}
