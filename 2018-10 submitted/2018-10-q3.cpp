/* APCS 2018-10-q3 DF-expression  */
#include <iostream>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

string str;
int N, idx = 0, ans = 0;

void unzip (int W) {
    if (str.at(idx) != '2') {
        if (str.at(idx) != '0')
            ans += (W*W);
        return;
    }
    ++idx;  unzip(W/2);
    ++idx;  unzip(W/2);
    ++idx;  unzip(W/2);
    ++idx;  unzip(W/2);
    return;
}

int main () {
    acceralateIO(0);
    cin >> str >> N;

    unzip(N);
    cout << ans << endl;
    
    return 0;
}