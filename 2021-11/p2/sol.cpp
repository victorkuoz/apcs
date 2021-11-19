#include <bits/stdc++.h>

#define MAX_HEIGHT 100

using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int h[3] = {0, 0, MAX_HEIGHT+1}, ans = 0;
    cin >> h[0];
    for (int i = 1; i < n; i++) {
        cin >> h[i%3];

        if (!h[(i+2)%3])
            ans += min(h[i%3], h[(i+1)%3]);
    }
    if (!h[(n+2)%3])
        ans += min(MAX_HEIGHT+1, h[(n+1)%3]);
    cout << ans << endl;
    return 0;
}