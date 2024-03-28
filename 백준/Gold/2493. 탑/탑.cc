#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int, int>> tower; // index, length

int main(void)
{
    cin >> n;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        while (!tower.empty()) {
            if (tower.top().second >= l) {
                cout << tower.top().first << ' ';
                break;
            }
            tower.pop();
        }
        if (tower.empty())
            cout << 0 << ' ';
        
        tower.push(make_pair(i + 1, l));
    }
    
    cout << '\n';
    
    return 0;
}
