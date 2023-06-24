#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b) 
{
    return (a > b);
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int weight = 0;
    int people_in_boat = 0;
    int start, end;
    int total = 0;
    
    sort(people.begin(), people.end(), compare);
    
    start = 0;
    end = people.size() - 1;
    while (start <= end && total < people.size()) {
        if (weight == 0) {
            answer++;
            weight += people[start++];
            people_in_boat++;
            total++;
        }
        else if (people_in_boat >= 2) {
            weight = 0;
            people_in_boat = 0;
        }
        else if (weight + people[end] <= limit) {
            weight += people[end--];
            people_in_boat++;
            total++;
        }
        else {
            weight = 0;
            people_in_boat = 0;
        }
    }
    if (total < people.size())
        answer++;
    
    
    return answer;
}