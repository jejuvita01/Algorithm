#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n; // 단어의 개수
vector<string> words; // 단어 모음 벡터
map<char, int> char_freq; // 알파벳 : 자리수 고려한 빈도값
map<char, int> char_int; // 알파벳 : 정수값

void calc_freq(string word)
{
    int ten = 1;
    int idx = (int)word.length() - 1;
    
    while (idx >= 0) {
        if (char_freq.find(word[idx]) == char_freq.end()) {
            char_freq.insert(make_pair(word[idx], ten));
        }
        else {
            char_freq[word[idx]] += ten;
        }
        idx--;
        ten *= 10;
    }
}

bool comp(pair<char, int> a, pair<char, int> b)
{
    return (a.second > b.second);
}

void match_char_to_int(void)
{
    vector<pair<char, int>> v(char_freq.begin(), char_freq.end());
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
        char_int.insert(make_pair(v[i].first, 9 - i));
}

int calc_sum(void)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        int ten = 1;
        int l = (int)words[i].length();
        for (int j = l - 1; j >= 0; j--) {
            num += ten * char_int[words[i][j]];
            ten *= 10;
        }
        sum += num;
    }
    
    return sum;
}

int main(void)
{
    cin >> n;
    string word;
    
    for (int i = 0; i < n; i++) {
        cin >> word;
        words.push_back(word);
        calc_freq(word);
    }
    
//    cout << char_freq.size() << '\n';
    
    match_char_to_int();
//    cout << char_int.size() << '\n';
//    map<char, int>::iterator it;
//    for (it = char_int.begin(); it != char_int.end(); it++)
//        cout << it->first << ": " << it->second << '\n';
    cout << calc_sum() << '\n';
    
    return 0;
}
