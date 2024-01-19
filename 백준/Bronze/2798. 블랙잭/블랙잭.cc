#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, m;
    vector<int> num;
    int max = 0;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (num[i] + num[j] + num[k] <= m) {
                    if (max < num[i] + num[j] + num[k])
                        max = num[i] + num[j] + num[k];
                }
            }
        }
    }

    cout << max << endl;
    
    return 0;
}
