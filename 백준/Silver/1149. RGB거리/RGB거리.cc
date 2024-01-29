#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    vector<vector<int>> rgb;
    int r, g, b;
    int answer;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        scanf("%d %d %d", &r, &g, &b);
        tmp.push_back(r);
        tmp.push_back(g);
        tmp.push_back(b);
        rgb.push_back(tmp);
    }
    
    for (int i = 1; i < n; i++) {
        rgb[i][0] += min(rgb[i - 1][1], rgb[i - 1][2]);
        rgb[i][1] += min(rgb[i - 1][0], rgb[i - 1][2]);
        rgb[i][2] += min(rgb[i - 1][0], rgb[i - 1][1]);
    }
    
    answer = min(rgb[n - 1][0], rgb[n - 1][1]);
    answer = min(answer, rgb[n - 1][2]);
    printf("%d\n", answer);
    
    return 0;
}
