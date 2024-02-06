#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1])
        return a[0] < b[0];
    else
        return false;
}

int main(void)
{
    int n;
    vector<vector<int>> point;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        vector<int> temp;
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        point.push_back(temp);
    }
    
    sort(point.begin(), point.end(), comp);
    
    for (int i = 0; i < n; i++) {
        cout << point[i][0] << ' ' << point[i][1] << '\n';
    }
    
    return 0;
}
