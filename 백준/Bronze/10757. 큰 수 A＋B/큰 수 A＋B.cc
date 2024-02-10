#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string a, b;
    vector<int> result;
    int aa, bb;
    int carry = 0;
    
    cin >> a >> b;
    
    aa = (int)a.length() - 1;
    bb = (int)b.length() - 1;
    
    while (aa >= 0 && bb >= 0) {
        result.push_back((a[aa] - '0' + b[bb] - '0' + carry) % 10);
        if (a[aa] - '0' + b[bb] - '0' + carry >= 10)
            carry = 1;
        else
            carry = 0;
        aa--;
        bb--;
    }
    if (aa >= 0) {
        while (aa >= 0) {
            result.push_back((a[aa] - '0' + carry) % 10);
            if (a[aa] - '0' + carry >= 10)
                carry = 1;
            else
                carry = 0;
            aa--;
        }
    }
    if (bb >= 0) {
        while (bb >= 0) {
            result.push_back((b[bb] - '0' + carry) % 10);
            if (b[bb] - '0' + carry >= 10)
                carry = 1;
            else
                carry = 0;
            bb--;
        }
    }
    if (carry == 1)
        result.push_back(1);
    
    for (int i = (int)result.size() - 1; i >= 0; i--)
        cout << result[i];
    cout << '\n';
    
    return 0;
}
