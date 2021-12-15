/* APCS 2018-02-p1 XOR 運算 */
#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000009
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);
    int n, x;
    while (cin >> n && cin >> x) {
        if (n > 1)
            cin.ignore(UINT_MAX, '\n');
        cout << ((n > 1) ? 0 : (x > MOD) ? (x % MOD) : x) << endl;
    }
    return 0;
}