#include <stdio.h>

int main(void)
{
    int n, five=0;
    int min=__INT_MAX__, num=__INT_MAX__;
    
    scanf("%d", &n);
    for(five=0;five<=n/5;five++)
    {
        if((n-5*five)%3==0) 
        {
            num = five+(n-5*five)/3;
            min = min>num ? num:min;
        }
    }
    if(num!=__INT_MAX__)    
        printf("%d", num);
    else
        printf("-1");
    return 0;
}