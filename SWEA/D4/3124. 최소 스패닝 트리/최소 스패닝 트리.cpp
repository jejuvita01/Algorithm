#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Q_type {
    int w;
    pair<int, int> a_b;
    
    bool operator<(const Q_type &q) const {
            return w > q.w;
    }
} q_type;

int tc;
int v, e;
long long weight = 0;
vector<q_type> graph[100000]; // graph[a] = {w, {a, b}}
int is_included[100000] = {0, };
int cnt = 0;

void init(void)
{
    for (int i = 0; i < v; i++)
        is_included[i] = 0;
    
    for (int i = 0; i < v; i++)
        graph[i].clear();
    
    weight = 0;
    cnt = 0;
}

void prim(void)
{
    priority_queue<q_type> heap;
    
    for (int i = 0; i < graph[0].size(); i++)
        heap.push(graph[0][i]);
    is_included[0] = 1;
    cnt++;
    
    while (heap.empty() == 0) {
        q_type q = heap.top();
        heap.pop();
        if (is_included[q.a_b.second])
            continue;
        else {
            is_included[q.a_b.second] = 1;
            weight += q.w;
            cnt++;
            for (int i = 0; i < graph[q.a_b.second].size(); i++) {
                if (!is_included[graph[q.a_b.second][i].a_b.second])
                    heap.push(graph[q.a_b.second][i]);
            }
        }
    }
}

int main(void)
{
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
        init();
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            q_type q = {w, make_pair(a - 1, b - 1)};
            graph[a - 1].push_back(q);
            q = {w, make_pair(b - 1, a - 1)};
            graph[b - 1].push_back(q);
        }
        prim();
        cout << '#' << t << ' ' << weight << '\n';
    }
    
    return 0;
}


/*
1
3 3
1 2 1
2 3 2
1 3 3
 
 
2
3 3
1 2 1
2 3 2
1 3 3
3 3
1 2 1
2 3 2
1 3 3
*/
