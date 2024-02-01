#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int tc;
    int n;
    int max = 0;
    vector<int> num;
    vector<int> cnt;
    
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n;
        num.push_back(n);
        if (n > max)
            max = n;
    }
    
    cnt.push_back(1);
    cnt.push_back(2);
    cnt.push_back(4);
    for (int i = 4 - 1; i < max; i++)
        cnt.push_back(cnt[i - 1] + cnt[i - 2] + cnt[i - 3]);
    
    for (int i = 0; i < tc; i++)
        cout << cnt[num[i] - 1] << "\n";
    
    return 0;
}
