/* APCS 2020-07-q1 購物車 */
#include <iostream>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);

    int A, B, N, ans = 0;
    cin >> A >> B >> N;

    for (int i = 0; i < N; i++) {
        int x, a = 0, b = 0;
        while (cin >> x && x != 0) {
            if (x == A)
                a++;
            else if (x == -A)
                a--;
            else if (x == B)
                b++;
            else if (x == -B)
                b--;
        }
        if (0 < a && 0 < b)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
