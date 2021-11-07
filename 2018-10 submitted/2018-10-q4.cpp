/* APCS 2018-10-q4 置物櫃出租 */
#include <iostream>
#include <vector>

using namespace std;

#define LIMIT (2e5)
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);
    int N, M, S;
    vector<bool> dp;

    while (cin >> N >> M >> S) {
        int x, sold = 0;
        dp.assign(M+1, false);

        dp.at(0) = true;
        for (int i = 0; i < N && cin >> x; i++) {
            sold += x;
            for (int idx = (M-x); idx >= 0; idx--)
                if (dp.at(idx))
                    dp.at(idx+x) = true;
        }
        
        int goal = (S-(M-sold)) < 0 ? 0 : (S-(M-sold));
        for (int i = goal; i <= M; i++)
            if (dp.at(i)) {
                cout << i << endl;
                break;
            }
    }
    return 0;
}