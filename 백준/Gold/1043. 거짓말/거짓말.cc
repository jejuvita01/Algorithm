// Union Find

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
    int n, m; // n: 사람 수, m: 파티 수
    int t; // t: 진실 아는 사람 수
    set<int> truth; // truth: 진실 아는 사람들
    vector<int> parent; // parent: 부모 노드를 저장
    vector<vector<int>> party; // party: party에 참석한 사람들을 저장
    int answer;
    
    cin >> n >> m;
    cin >> t;
    
    for (int i = 0; i < m + 1; i++)
        parent.push_back(i);
    
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        truth.insert(x);
    }
    
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        int num;
        int x;
        bool truth_flag = false;
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> x;
            tmp.push_back(x);
            if (truth.size() != 0 && truth.find(x) != truth.end()) {
                truth_flag = true;
                parent[i + 1] = 0;
            }
        }
        if (truth_flag) {
            for (int j = 0; j < tmp.size(); j++)
                truth.insert(tmp[j]);
        }
        party.push_back(tmp);
    }
    
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            bool truth_flag = false;
            for (int j = 0; j < party[i].size(); j++) {
                if (truth.size() != 0 && truth.find(party[i][j]) != truth.end()) {
                    truth_flag = true;
                    parent[i + 1] = 0;
                }
            }
            if (truth_flag) {
                for (int j = 0; j < party[i].size(); j++)
                    truth.insert(party[i][j]);
            }
        }
    }
    
    answer = m;
    for (int i = 1; i < m + 1; i++) {
        if (parent[i] == 0)
            answer--;
    }
    
    cout << answer << endl;
    
    return 0;
}
