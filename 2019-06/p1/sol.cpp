/* APCS 2019-06-p1 籃球比賽 */
#include <bits/stdc++.h>

using namespace std;

#define getPoint(cur) {for (int i = 0; i < 4 && cin >> x; i++) cur += x;}

int main () {
    int H1 = 0, H2 = 0, A1 = 0, A2 = 0, x;

    getPoint(H1);
    getPoint(A1);
    getPoint(H2);
    getPoint(A2);

    cout << H1 << ":" << A1 << endl << H2 << ":" << A2 << endl;
    if (H1 > A1 && H2 > A2)
        cout << "Win\n";
    else if (H1 < A1 && H2 < A2)
        cout << "Lose\n";
    else
        cout << "Tie\n";
    return 0;
}