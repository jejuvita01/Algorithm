#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    int x;
    vector<int> people;
    int first, second;
    long long answer = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        people.push_back(x);
    }
    cin >> first >> second;
    
    for (int i = 0; i < n; i++) {
        answer++;
        people[i] -= first;
        if (people[i] > 0)
            answer += ceil(people[i] / (double)second);
    }
    
    cout << answer << endl;
    
    return 0;
}
