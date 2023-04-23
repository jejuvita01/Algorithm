#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x, y; // saving the point coordinates
    vector<vector<int>> point(501); // saving the visited points
    int point_index = 0; // use to save point's size (cause point.size() == 501)
    
    x = y = 0; // set the point to origin
    // starts with origin, so push_back the origin coordinate
    point[point_index].push_back(x);
    point[point_index++].push_back(y);
    // cout << point[0][0] << endl << point[0][1];
    
    // looping through range [0, dirs length)
    for (int i = 0; i < dirs.length(); i++) {
        int tmp_x, tmp_y; // saving the changed coorditanes
        tmp_x = x;
        tmp_y = y;
        
        // change tmp_x, tmp_y value according to command
        switch (dirs[i]) {
            case 'U': if (y < 5) tmp_y++; break;
            case 'D': if (y > -5) tmp_y--; break;
            case 'R': if (x < 5) tmp_x++; break;
            case 'L': if (x > -5) tmp_x--; break;
            default: break;
        }
        
        // change answer considering past movement
        bool did_i_pass = false; // check if already passed that path
        for (int p = 0; p < point_index; p++) {
            if (point[p][0] == tmp_x && point[p][1] == tmp_y) {
                if (p == 0) {
                    if (point[p + 1][0] == x && point[p + 1][1] == y) 
                        did_i_pass = true;
                }
                else if (p == point_index - 1) {
                    if (point[p - 1][0] == x && point[p - 1][1] == y)
                        did_i_pass = true;
                }
                else {
                    if ((point[p + 1][0] == x && point[p + 1][1] == y) || (point[p - 1][0] == x && point[p - 1][1] == y))
                        did_i_pass = true;
                }
            }
        }
        
        if (x != tmp_x || y != tmp_y) {
            if (did_i_pass == false) {
                cout << "answer++ at // x: " << tmp_x << ", y: " << tmp_y << endl;
                answer++;
            }
            x = tmp_x;
            y = tmp_y;
            point[point_index].push_back(x);
            point[point_index++].push_back(y);
        }
    }
        
    return answer;
}