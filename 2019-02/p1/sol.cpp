/* APCS 2019-02-p1 城市移動 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C, L;
    cin >> N >> C;

    /* 每回合先計算分數，後判斷下個回合所在城市 */
    uint32_t ans = 0;
    for (int i = 0; i < N && cin >> L; i++) {
        switch (C) {
            case 1 :
                ans += L;
                C = (L%2) ? 1 : 2;
                break;
            case 2 :
                ans += 2*L;
                C = (L%3) ? 1 : 3;
                break;
            case 3 :
                ans += (L/10);
                C = (L%5) ? 1 : 3;
                break;
        }
    }
    cout << ans << endl;
    return 0;
}