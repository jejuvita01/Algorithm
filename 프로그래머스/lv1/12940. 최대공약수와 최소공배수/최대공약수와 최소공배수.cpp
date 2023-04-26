#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int r = 0;
    int n_copy = n;
    int m_copy = m;
    
    if (n < m) {
        int tmp = n;
        n = m;
        m = tmp;
    }
    while (m != 0) {
        r = n % m;
        n = m;
        m = r;
    }
    answer.push_back(n);
    answer.push_back((n_copy * m_copy) / n);
    
    return answer;
}