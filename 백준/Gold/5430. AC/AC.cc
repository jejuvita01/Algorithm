#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

void get_deque(deque<int>& num, int n)
{
    string str;
    string sep = ",";
    int cur_pos = 1;
    int pos = 0;
    int len;
    string result;
    
    cin >> str;
    if (n == 0) return;
    
    while ((pos = str.find(sep, cur_pos)) != str.npos) {
        len = pos - cur_pos;
        result = str.substr(cur_pos, len);
        num.push_back(stoi(result));
        cur_pos = pos + 1;
    }
    len = pos - cur_pos;
    result = str.substr(cur_pos, len);
    num.push_back(stoi(result));
    
    return;
}

bool deque_ac(deque<int>& num, string command, bool& start)
{
    bool is_front = true; // true면 첫번째 요소 삭제, false면 마지막 요소 삭제
    
    start = true;
    for (int i = 0; i < command.length(); i++) {
        if (command[i] == 'R') {
            is_front = !is_front;
            start = !start;
        }
        else { // 'D'
            if (num.size() == 0)
                return false;
            else {
                if (is_front)
                    num.pop_front();
                else
                    num.pop_back();
            }
        }
    }
    
    return true;
}

int main(void)
{
    int tc;
    string command;
    int n;
    bool flag = true;
    bool start = true; // true면 앞에서부터 출력, false면 뒤에서부터 출력
    
    scanf("%d", &tc);
    
    for (int i = 0; i < tc; i++) {
        cin >> command >> n;
        deque<int> num;
        get_deque(num, n);
        flag = deque_ac(num, command, start);
        if (flag == true) {
            deque<int>::iterator iter;
            int cnt = 0;
            cout << '[';
            if (num.size() != 0) {
                if (start == true) {
                    for (iter = num.begin(); iter != num.end(); iter++) {
                        cout << *iter;
                        cnt++;
                        if (cnt != num.size())
                            cout << ",";
                    }
                }
                else {
                    for (iter = num.end() - 1; iter != num.begin(); iter--) {
                        cout << *iter;
                        cnt++;
                        if (cnt != num.size())
                            cout << ",";
                    }
                    cout << num.front();
                }
            }
            cout << ']' << endl;
        }
        else {
            cout << "error" << endl;
        }
    }
    
    return 0;
}
