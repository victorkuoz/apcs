/* APCS 2018-06-p1 特殊編碼 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;

    int a, b ,c, d;
    while (cin >> n) {
        /* ignore newline character */
        cin.ignore();

        for (int i = 0; i < n; i++) {
            getline(cin, s);

            if (s.at(0)-'0') {
                if (s.at(6)-'0')
                    cout << 'D';
                else if (s.at(2)-'0')
                    cout << 'F';
                else
                    cout << 'E';
            }
            else {
                if (!(s.at(2)-'0'))
                    cout << 'C';
                else if (s.at(4)-'0')
                    cout << 'B';
                else
                    cout << 'A';
            }
        }
        cout << '\n';
    }
    return 0;
}