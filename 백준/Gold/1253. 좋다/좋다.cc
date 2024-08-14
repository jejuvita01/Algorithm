#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
    int n;
    vector<int> num;
    int cnt = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    
    sort(num.begin(), num.end());
    
    for (int i = 0; i < n; i++) {
        int start, end;
        start = 0;
        end = n - 1;
        bool flag = false;
        while (start < end) {
            if (start != i && end != i) {
                if (num[start] + num[end] == num[i]) {
                    flag = true;
                    break;
                }
                else if (num[start] + num[end] < num[i])
                    start++;
                else if (num[start] + num[end] > num[i])
                    end--;
                else {
                    start++;
                    end--;
                }
            }
            else {
                if (start == i)
                    start++;
                else if (end == i)
                    end--;
            }
        }
        if (flag)
            cnt++;
    }
    
    cout << cnt << '\n';
    
    
    return 0;
}
