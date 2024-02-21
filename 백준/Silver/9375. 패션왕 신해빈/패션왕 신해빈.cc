#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main(void)
{
    int tc;
    int n;
    
    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        cin >> n;
        map<string, int> kind_num;
        for (int j = 0; j < n; j++) {
            string name, kind;
            cin >> name >> kind;
            if (kind_num.find(kind) == kind_num.end()) {
                kind_num.insert(make_pair(kind, 1));
            }
            else {
                kind_num[kind]++;
            }
        }
        int answer = 1;
        map<string, int>::iterator iter;
        for (iter = kind_num.begin(); iter != kind_num.end(); iter++)
            answer *= iter->second + 1;
        answer--;
        cout << answer << '\n';
    }
    
    return 0;
}
