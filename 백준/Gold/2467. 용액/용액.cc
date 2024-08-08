#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    vector<int> num;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    
//    sort(num.begin(), num.end());
    
    int start, end;
    int min_start, min_end;
    int min;
    min_start = start = 0;
    min_end = end = n - 1;
    min = num[start] + num[end];
    
//    cout << min_start << ' ' << min_end << '\n';
    
    while (start < end && start < n && end > 0) {
        if (abs(num[start] + num[end]) < abs(min)) {
            min_start = start;
            min_end = end;
            min = num[min_start] + num[min_end];
        }
        if (start < n - 1 && abs(num[start + 1] + num[end]) < abs(num[start] + num[end])) {
            if (end > 0 && abs(num[start] + num[end - 1]) < abs(num[start + 1] + num[end])) {
                end--;
            }
            else {
                start++;
            }
        }
        else {
            if (end > 0 && abs(num[start] + num[end - 1]) < abs(num[start] + num[end])) {
                end--;
            }
            else {
                start++;
                end--;
            }
        }
//        cout << min_start << ' ' << min_end << '\n';
    }
    
    cout << num[min_start] << ' ' << num[min_end] << '\n';
    
    return 0;
}

/*
6
-100 0 1 2 30 70
*/
