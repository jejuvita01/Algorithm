#include <iostream>
#include <deque>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int tc, n, k;
string str;
deque<int> dq;
set<long long> nums;

void make_deque(void)
{
    for (int i = 0; i < n; i++) {
        int num;
        switch (str[i]) {
            case 'A': num = 10; break;
            case 'B': num = 11; break;
            case 'C': num = 12; break;
            case 'D': num = 13; break;
            case 'E': num = 14; break;
            case 'F': num = 15; break;
            case '0': num = 0; break;
            case '1': num = 1; break;
            case '2': num = 2; break;
            case '3': num = 3; break;
            case '4': num = 4; break;
            case '5': num = 5; break;
            case '6': num = 6; break;
            case '7': num = 7; break;
            case '8': num = 8; break;
            case '9': num = 9; break;
            default: num = -1; break;
        }
        if (num != -1)
            dq.push_back(num);
    }
    
//    cout << "숫자들\n";
//    for (int i = 0; i < n; i++) {
//        cout << dq[i] << ' ';
//    }
//    cout << "숫자 개수: " << dq.size() << '\n';
//    cout << '\n';
}

long long get_num(int start)
{
    long long num = 0;
    long long hex = 1;
    
    for (int i = (n / 4) - 1; i >= 0; i--) {
//        cout << dq[start + i] << ' ';
        num += (hex * dq[start + i]);
        hex *= 16;
//        cout << num << '\n';
    }
    
    return num;
}

void make_nums(void)
{
    for (int i = 0; i < (n / 4) + 1; i++) { // 회전시키면서
//        cout << "회전: " << i << '\n';
        for (int j = 0; j < 4; j++) { // 잘라서 숫자 만들기
            // cout << '\n' << j * (n / 4) << '\n';
//            cout << "숫자 범위: " << j * (n / 4) << "~" << (j + 1) * (n / 4) << '\n';
            long long number = get_num(j * (n / 4));
            nums.insert(number);
//            cout << number << '\n';
        }
        int push = dq.front();
        dq.pop_front();
        dq.push_back(push);
    }
}

long long get_answer(void)
{
    long long answer = 0;
    
    set<long long>::iterator iter;
    iter = nums.begin();
    
    for (int i = 0; i < nums.size() - k; i++)
        iter++;
    
    answer = *iter;
    
    return answer;
}

int main(void)
{
    cin >> tc;
    
    for (int test = 1; test <= tc; test++) {
        cin >> n >> k;
        cin >> str;
//        cout << str;
        dq.clear();
        nums.clear();
        make_deque(); // str을 덱으로 만들고
        make_nums(); // 덱으로 숫자들을 만든다
//        cout << "\nSET_SIZE: " << nums.size() << '\n';
        cout << "#" << test << ' ' << get_answer() << '\n';
    }
    
    return 0;
}

/*
2
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8
*/


// 비밀번호 만들기 SWEA

/*
5
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8
20 14
88F611AE414A751A767B
24 16
044D3EBA6A647B2567A91D0E
28 11
8E0B7DD258D4122317E3ADBFEA99

#1 503
#2 55541
#3 334454
#4 5667473
#5 182189737
*/
