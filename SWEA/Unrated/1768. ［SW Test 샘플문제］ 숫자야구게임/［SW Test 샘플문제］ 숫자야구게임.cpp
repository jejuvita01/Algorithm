#define N 4

typedef struct {
           int strike;
    int ball;
} Result;

// API

extern Result query(int guess[]);



int case_cnt = 0;
int case_num[9999][6];
int no_answer[10] = {0, };
int is_answer[10] = {0, };

bool is_dup(int n)
{
    int num[10] = {0, };
    int cnt = 0;
    
    if (n < 1000)
        num[0] = 1;
    
    while (n > 0) {
        num[n % 10] = 1;
        n /= 10;
    }
    
    for (int i = 0; i < 10; i++)
        if (num[i] == 1)
            cnt++;
    
    return (cnt != 4);
}

bool is_possible(int n)
{
    int num[4];
    
    num[0] = n / 1000;
    num[1] = (n / 100) % 10;
    num[2] = (n / 10) % 10;
    num[3] = n % 10;
    
    for (int i = 0; i < 4; i++)
        if (no_answer[num[i]] == 1)
            return false;
    
    for (int i = 0; i < case_cnt; i++) {
        int cnt, same;
        cnt = same = 0;
        for (int j = 0; j < 4; j++) {
            if (case_num[i][j] == num[j]) same++;
            for (int k = 0; k < 4; k++)
                if (case_num[i][j] == num[k])
                    cnt++;
        }
        if (cnt == 4)
            return false;
        else if (same > case_num[i][4])
            return false;
    }
    
    return true;
}

void doUserImplementation(int guess[]) {
    Result q;
    
    case_cnt = 0;
    for (int i = 0; i < 9; i++) {
        no_answer[i] = 0;
        is_answer[i] = 0;
    }
    
    for (int i = 123; i <= 9876; i++) {
        if (!is_dup(i) && is_possible(i)) {
            guess[0] = i / 1000;
            guess[1] = (i / 100) % 10;
            guess[2] = (i / 10) % 10;
            guess[3] = i % 10;
            
            q = query(guess);
            for (int j = 0; j < 4; j++)
                case_num[case_cnt][j] = guess[j];
            case_num[case_cnt][4] = q.strike;
            case_num[case_cnt][5] = q.ball;
            case_cnt++;
            
            if (q.strike == 4)
                return;
            else if (q.strike == 0 && q.ball == 0) {
                for (int j = 0; j < 4; j++) {
                    no_answer[guess[j]] = 1;
                }
            }
            else if (q.ball == 4 || (q.ball == 3 && q.strike == 1) || (q.ball == 2 && q.strike == 2) || (q.ball == 1 && q.strike == 3)) {
                for (int n = 0; n < 4; n++)
                    is_answer[guess[n]] = 1;
                break;
            }
        }
    }
    
    int new_guess[4];
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    // 네개 순서 바꿔서 query 넣고 맞으면 그거 guess에 넣고 break;
                    if (a != b && b != c && c != d && d != a) {
                        new_guess[0] = guess[a];
                        new_guess[1] = guess[b];
                        new_guess[2] = guess[c];
                        new_guess[3] = guess[d];
                        Result q = query(new_guess);
                        if (q.strike == 4) {
                            guess[0] = new_guess[0];
                            guess[1] = new_guess[1];
                            guess[2] = new_guess[2];
                            guess[3] = new_guess[3];
                            return;
                        }
                    }
                }
            }
        }
    }
}
