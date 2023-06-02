#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> players_map;
    
    for (int i = 0; i < players.size(); i++)
        players_map.insert(make_pair(players[i], i));
    
    for (int i = 0; i < callings.size(); i++) {
        int front_index = players_map[callings[i]] - 1;
        string front_name = players[players_map[callings[i]] - 1];
        players[front_index] = callings[i];
        players[front_index + 1] = front_name;
        players_map[callings[i]]--;
        players_map[front_name]++;
        
    }
    
    return players;
}