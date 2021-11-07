/* APCS 2020-01-q1 猜拳模擬 */
#include <iostream>
#include <vector>

using namespace std;

#define Scissors 2
#define Stone 0
#define Paper 5

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);
    int F, N;
    cin >> F >> N;

    vector<int> plays(++N, 1);
    for (int i = 1; i < N; i++)
        cin >> plays.at(i);
    
    int i = 1, end = 0;
    for ( ; i < N && !end; i++) {
        cout << F << " ";
        /* 分出勝負 */
        if (plays.at(i) != F) {
            if ((F == Scissors && plays.at(i) == Paper) ||
                (F == Paper && plays.at(i) == Stone)    ||
                (F == Stone && plays.at(i) == Scissors) )
                    end = 1;
            else
                end = (-1);
        }
        /* 平手 */
        else {
            /* 判斷下一輪 */
            if (plays.at(i-1) != plays.at(i))
                F = plays.at(i);
            else {
                if (plays.at(i) == Scissors)
                    F = Stone;
                else if (plays.at(i) == Stone)
                    F = Paper;
                else
                    F = Scissors;
            }
        }
    }

    if (end > 0)
        cout << ": Won at round " << --i << endl;
    else if (end < 0)
        cout << ": Lost at round " << --i << endl;
    else
        cout << ": Drew at round " << --i << endl;
    return 0;
}
