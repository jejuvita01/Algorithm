#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    int n, tc;
    vector<int> num;
    vector<int> sum;
    int x;
    int temp = 0;
    
    scanf("%d %d", &n, &tc);
    
    for (int i = 0; i < n; i++) {
        sum.push_back(temp);
        scanf("%d", &x);
        num.push_back(x);
        temp += x;
    }
    sum.push_back(temp);
    
    for (int i = 0; i < tc; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", sum[end] - sum[start - 1]);
    }
    
    return 0;
}
