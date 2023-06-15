#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return (a > b);
}

string solution(string X, string Y) {
    string answer = "";
    vector<int> x;
    vector<int> y;
    vector<int> same;
    int x_index, y_index;
    
    // make string X to vector x
    for (int i = 0; i < X.length(); i++)
        x.push_back(X[i] - '0');
    
    // make string Y to vector y
    for (int i = 0; i < Y.length(); i++)
        y.push_back(Y[i] - '0');
    
    // sort x and y
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    // make same vector by comparing each vector's elements
    x_index = y_index = 0;
    while (x_index < x.size() && y_index < y.size()) {
        if (x[x_index] == y[y_index]) {
            same.push_back(x[x_index]);
            x_index++;
            y_index++;
        }
        else if (x[x_index] < y[y_index])
            x_index++;
        else
            y_index++;
    }
    
    // sort same for descending order
    sort(same.begin(), same.end(), compare);
    
    // make the conclusion
    if (same.size() == 0)
        answer = "-1";
    else if (same[0] == 0)
        answer = "0";
    else {
        for (int i = 0; i < same.size(); i++)
            answer += same[i] + '0';
    }
    
    return answer;
}