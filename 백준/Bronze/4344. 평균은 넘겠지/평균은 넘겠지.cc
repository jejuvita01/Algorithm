#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    int num;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        int s;
        vector<int> student;
        int sum = 0;
        int answer = 0;
        for (int j = 0; j < num; j++) {
            cin >> s;
            sum += s;
            student.push_back(s);
        }
        double avg = sum / (double)student.size();
        for (int j = 0; j < num; j++)
            if (student[j] > avg)
                answer++;
        
        cout << fixed;
        cout.precision(3);
        cout << (answer / (double)student.size()) * 100 + 0.0001 << "%" << endl;
    }
    
    return 0;
}
