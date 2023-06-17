#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    string s = "";
    int answer = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        map<char, int> is_exist;
        int flag = true;
        for (int j = 0; j < s.length(); j++) {
            if (j == 0)
                is_exist.insert(make_pair(s[j], 1));
            else {
                if (s[j] != s[j - 1]) {
                    if (is_exist.find(s[j]) != is_exist.end()) {
                        flag = false;
                        j = s.length();
                    }
                    else
                        is_exist.insert(make_pair(s[j], 1));
                }
            }
        }
        if (flag == true)
            answer++;
    }
    cout << answer << endl;

    return 0;
}
