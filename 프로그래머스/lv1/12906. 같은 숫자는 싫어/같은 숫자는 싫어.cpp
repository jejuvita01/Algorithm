#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    vector<int>::iterator iter;
    
    if (arr.size())
        answer.push_back(arr[0]);
    for (iter = arr.begin(); iter != arr.end(); iter++) {
        if (*iter != answer.back())
            answer.push_back(*iter);
    }
    
    /*
    for (iter = arr.begin(); iter != arr.end(); iter++) {
        if (*(iter) != *(iter + 1))
            answer.push_back(*iter);
    }
    if (answer.size() != 0)
        if (*(iter - 1) != *(answer.end() - 1))
            answer.push_back(*(iter - 1));
    */
    
    return answer;
}