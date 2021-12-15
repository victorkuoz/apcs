/* APCS 2018-02-p2 反轉表 */
#include <bits/stdc++.h>

using namespace std;

#define L 1000
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main() {
    acceralateIO(0);

    string line;
    vector<int> A(L, 0);
    stringstream str2int;

    while (getline(cin, line)) {
        str2int.str("");
        str2int.clear();
        str2int << line;

        int X, N = 0;
        while (!str2int.eof()) {
            str2int >> X;
            for (int i = 0, zero = 0; ; i++) {
                if (!A.at(i))
                    zero++;
                if (zero > X) {
                    A.at(i) = (++N);
                    break;
                }
            }
        }

        for (int i = 0; i < N; A.at(i) = 0, i++)
            cout << A.at(i) << ((i != (N-1)) ? " " : "\n");
    }
    return 0;
}