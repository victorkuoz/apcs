/* APCS 2018-10-q1 王牌投手 */
#include <iostream>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);

    int N;
    cin >> N;

    int rank, sum = 0, cnt = 0;
    for (int i = 0; i < N && cin >> rank; i++) {
        int x, val, max = 0;

        for (int i = 1; i <= 10 && cin >> x; i++) {
            if (i == rank)
                val = x;
            if (max < x)
                max = x;
        }
        sum += val;
        if (val == max)
            cnt++;
    }
    cout << sum << '\n' << cnt << '\n';
    return 0;
}