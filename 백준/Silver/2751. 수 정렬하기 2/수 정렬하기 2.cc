#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int n;
    int x;
    set<int> num;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        num.insert(x);
    }
    
    set<int>::iterator iter;
    for (iter = num.begin(); iter != num.end(); iter++)
        printf("%d\n", *iter);
    
    return 0;
}
