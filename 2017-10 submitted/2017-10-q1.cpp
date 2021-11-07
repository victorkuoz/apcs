/* APCS 2017-10-q1 邏輯運算子 */
#include <iostream>
using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    while (cin >> a >> b >> c) {
        /* 注意 C++ 並無支援"邏輯"上的 XOR，因此轉換成"位元運算" */
        if (a > 0)  a = 1;
        if (b > 0)  b = 1;
        
        /* 注意位元運算優先順位較低，一定要加括號 */
        string ans("");
        if ((a&b) == c)
            ans += "AND\n";
        if ((a|b) == c)
            ans += "OR\n";
        if ((a^b) == c)
            ans += "XOR\n";
        if (ans == "")
            ans += "IMPOSSIBLE\n";
        cout << ans;
    }
    return 0;
}