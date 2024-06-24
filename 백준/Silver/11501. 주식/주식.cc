#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tc;
int day;
vector<int> price;

void get_input(void)
{
    price.clear();
    
    for (int i = 0; i < day; i++) {
        int p;
        cin >> p;
        price.push_back(p);
    }
}

long long get_max_profit(void)
{
    int max = 0;
    long long answer = 0;
    
    for (int i = day - 1; i >= 0; i--) {
        if (max < price[i])
            max = price[i];
        answer += ((max - price[i]) > 0 ? (max - price[i]) : 0);
    }
    
    return answer;
}

int main(void)
{
    cin >> tc;
    
    for (int test = 0; test < tc; test++) {
        cin >> day;
        get_input();
        cout << get_max_profit() << '\n';
    }
    
    return 0;
}
