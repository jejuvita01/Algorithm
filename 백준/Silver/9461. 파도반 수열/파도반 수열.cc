#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int tc;
    vector<long long> arr;
    
    cin >> tc;
    
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    for (int i = 3; i <= 100; i++) {
        arr.push_back(arr[i - 3] + arr[i - 2]);
    }
    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;
        cout << arr[n - 1] << '\n';
    }
    
    return 0;
}
