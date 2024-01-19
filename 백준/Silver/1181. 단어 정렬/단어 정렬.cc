#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

/*
길이가 짧은 것부터
길이가 같으면 사전 순으로
*/

bool comp(string a, string b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length()) {
        if (a <= b)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main(void)
{
    int n;
    set<string> words_set;
    string w;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> w;
        words_set.insert(w);
    }
    
    vector<string> words_vector(words_set.begin(), words_set.end());
    
    sort(words_vector.begin(), words_vector.end(), comp);
    
    for (int i = 0; i < words_vector.size(); i++) {
        cout <<  words_vector[i] << endl;
    }
    
    return 0;
}
