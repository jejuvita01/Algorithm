#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight = 0;
    int index = 0;
    int tmp = 0;
    queue<int> on_bridge;
    
    for (int i = 0; i < bridge_length; i++)
        on_bridge.push(0);
    
    while (index < truck_weights.size()) {
        current_weight -= on_bridge.front();
        on_bridge.pop();
        if (current_weight + truck_weights[index] <= weight) {
            on_bridge.push(truck_weights[index]);
            current_weight += truck_weights[index];
            index++;
        }
        else
            on_bridge.push(0);
        answer++;
    }
    
    for (index = 0; index < bridge_length; index++) {
        tmp++;
        if (on_bridge.front()) {
            answer += tmp;
            tmp = 0;
        }
        on_bridge.pop();
    }
    
    return answer;
}