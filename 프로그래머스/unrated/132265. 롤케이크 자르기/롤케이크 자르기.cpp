#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    set<int> a(topping.begin(), topping.begin() + 1);
    set<int> b(topping.begin() + 1, topping.end());
    
    // cout << a.size() << endl << b.size() << endl;
    
    for (int i = 1; i < topping.size(); i++) {
        a.insert(topping[i]);
        if (find(topping.begin() + i + 1, topping.end(), topping[i]) == topping.end() && b.find(topping[i]) != b.end())
            b.erase(b.find(topping[i]));
        if (a.size() == b.size())
            answer++;
        // cout << "i: " << i << endl << a.size() << ", " << b.size() << endl;
    }
    
    return answer;
}