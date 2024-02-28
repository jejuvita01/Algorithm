#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
    int tc;
    
    cin >> tc;
    
    for (int t = 0; t < tc; t++) {
        int N, M, Y, year;
        vector<string> n;
        vector<string> m;
        string tmp;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            n.push_back(tmp);
        }
        for (int i = 0; i < M; i++) {
            cin >> tmp;
            m.push_back(tmp);
        }
        cin >> Y;
        cout << '#' << t + 1;
        for (int i = 0; i < Y; i++) {
            cin >> year;
            cout<< ' ' << (n[year % N - 1 < 0 ? N - 1 : year % N - 1] + m[year % M - 1 < 0 ? M - 1 : year % M - 1]);
        }
        cout << '\n';
    }
    
    return 0;
}
