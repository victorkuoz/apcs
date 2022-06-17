/* APCS 2019-10-q1 音階校正 */
#include <iostream>
#include <deque>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

deque<int> prevs;

int median () {
    return (prevs[0] + prevs[1] + prevs[2]) -
            max(prevs[0], max(prevs[1], prevs[2])) - 
            min(prevs[0], min(prevs[1], prevs[2]));
}

int main () {
    acceralateIO(0);
    int x, N;

    while (cin >> N) {
        prevs.clear();
        for (int i = 0; i < 3 && cin >> x; i++) {
            if (i != 0)
                cout << " ";
            cout << x;
            prevs.push_back(x);
        }

        for (int i = 3; i < N && cin >> x; i++) {
            if (5 < x - prevs.back())
                x = median();
            cout << " " << x;
            prevs.pop_front();
            prevs.push_back(x);
        }
        cout << endl;
    }
    return 0;
}