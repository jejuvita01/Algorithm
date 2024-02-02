#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
    string sent;
    
    while (getline(cin, sent)) {
        cout << sent << endl;
    }
    
    return 0;
}
