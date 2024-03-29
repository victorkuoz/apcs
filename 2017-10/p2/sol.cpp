/* APCS 2017-10-p2 交錯字串 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string line;

    while (cin >> N >> line) {
        /* 方便運算，行尾多加一相反大小寫之字母 */
        line += isupper(line.back()) ? 'a' : 'A';

        int ans = 0, pre = 0, len = 0, size = line.size();
        for (int idx = 0; idx < size; idx++, len++) {
            /* 開頭或與大小寫改變時 */
            if (!idx || (line.at(idx-1) < 'a' && line.at(idx) >= 'a') || (line.at(idx-1) >= 'a' && line.at(idx) < 'a')) {
                /* len 為前一段連續大寫或小寫的長度 */
                if (len < N) {
                    if (pre > ans)
                        ans = pre;
                    pre = 0;
                }
                else if (len > N) {
                    if (pre + N > ans)
                        ans = (pre + N);
                    pre = N;
                }
                else {
                    if (pre + N > ans)
                        ans = (pre + N);
                    pre += N;
                }
                len = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}