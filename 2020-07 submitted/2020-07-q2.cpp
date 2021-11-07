/* APCS 2020-07-q2 骰子 */
#include <iostream>
#include <vector>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

inline void swap(uint16_t &x, uint16_t &y) {
    uint16_t i = x;
    x = y;
    y = i;
}

class Dice {
private:
    uint16_t U = 1, F = 4, R = 2;

public:
    void turnRight() {
        R = (7-R);
        swap(U,R);
    }

    void turnFront() {
        F = (7-F);
        swap(U,F);
    }

    uint16_t getU() {
        return U;
    }
};

inline void swap(Dice &x, Dice &y) {
    Dice d = x;
    x = y;
    y = d;
}

int main () {
    acceralateIO(0);

    int N, M;
    cin >> N >> M;

    vector<Dice> dices(N, Dice());
    
    int a, b;
    for (int i = 0; i < M && cin >> a >> b; i++) {
        if (b < (-1))
            dices.at(a-1).turnRight();
        else if (b < 0)
            dices.at(a-1).turnFront();
        else
            swap(dices.at(a-1), dices.at(b-1));
    }

    for (int i = 0; i < N; i++) {
        if (i != 0)
            cout << " ";
        cout << dices.at(i).getU();
    }
    cout << endl;
    return 0;
}