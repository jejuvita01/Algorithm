#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index = 0;

bool compare(string a, string b) {
    return (a[index] != b[index] ? a[index] < b[index] : a < b);
};

vector<string> solution(vector<string> strings, int n) {     
    index = n;
    
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}