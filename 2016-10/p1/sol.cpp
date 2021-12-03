/* APCS 2016-10-p1 三角形辨別 */
#include <bits/stdc++.h>

#define swap(a,b) { int tmp = a; a = b; b = tmp; }

using namespace std;

int main () {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a > b)
            swap(a,b);
        if (b > c)
            swap(b,c);
        if (a > b)
            swap(a,b);

        cout << a << " " << b << " "<< c << endl;

        if ((a + b) <= c)
            cout << "No\n";
        else if (a*a + b*b < c*c)
            cout << "Obtuse\n";
        else if (a*a + b*b > c*c)
            cout << "Acute\n";
        else
            cout << "Right\n";
    }
    return 0;
}