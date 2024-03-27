#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b)
{
    return a.second < b.second;
}

int find_parent(vector<int>& parent, int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find_parent(parent, parent[x]);
}

bool same_parent(vector<int>& parent, int a, int b)
{
    int a_p = find_parent(parent, a);
    int b_p = find_parent(parent, b);
    
    return (a_p == b_p);
}

void union_parent(vector<int>& parent, int a, int b)
{
    int a_p = find_parent(parent, a);
    int b_p = find_parent(parent, b);
    
    if (a_p < b_p)
        parent[b_p] = a_p;
    else
        parent[a_p] = b_p;
}

double get_min_money(int island, double E, vector<long long> points[])
{
    // 환경 부담 세율(E)과 각 해저터널 길이(L)의 제곱의 곱(E * L^2)만큼 지불
    double answer = 0;
    vector<pair<pair<int, int>, double>> Edge; // pair<pair<섬1, 섬2>, 거리>>
    vector<int> parent;
    
    for (int i = 0; i < island - 1; i++) {
        for (int j = i + 1; j < island; j++) {
            long long dx = points[i][0] - points[j][0];
            long long dy = points[i][1] - points[j][1];
            double dist = E * (dx * dx + dy * dy);
            Edge.push_back(make_pair(make_pair(i, j), dist));
        }
    }
    
    sort(Edge.begin(), Edge.end(), comp);
    
    for (int i = 0; i < island; i++)
        parent.push_back(i);
    
    for (int i = 0; i < Edge.size(); i++) {
        int a = Edge[i].first.first;
        int b = Edge[i].first.second;
        if (!same_parent(parent, a, b)) {
            answer += Edge[i].second;
            union_parent(parent, a, b);
        }
    }
    
    return answer;
}

int main(void)
{
    long long tc;
    
    cin >> tc;
    
    cout << fixed;
    cout.precision(0);
    
    for (long long t = 0; t < tc; t++) {
        int island;
        double E;
        cin >> island;
        vector<long long> points[island];
        for (int i = 0; i < island; i++) {
            int x;
            cin >> x;
            points[i].push_back(x);
        }
        for (int i = 0; i < island; i++) {
            int y;
            cin >> y;
            points[i].push_back(y);
        }
        cin >> E;
        cout << '#' << t + 1 << ' ' << get_min_money(island, E, points) << '\n';
    }
}
