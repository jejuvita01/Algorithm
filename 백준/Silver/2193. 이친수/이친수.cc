#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<long long> fibo;
    int n;
    
    cin >> n;
    
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i <= n; i++)
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);

    cout << fibo[n] << endl;
    
    return 0;
}
