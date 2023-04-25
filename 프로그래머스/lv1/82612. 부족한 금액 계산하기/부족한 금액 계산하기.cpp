using namespace std;

long long solution(int price, int money, int count)
{
    long long out = 0;
    
    for (int i = 0; i < count; i++) {
        out += price * (i + 1);
    }

    return (money - out) >= 0 ? 0: -1 * (money - out);
}