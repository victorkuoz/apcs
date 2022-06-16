/* APCS 2019-06-p4 美麗的彩帶 */
#include <bits/stdc++.h>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    /* 加速讀寫 */
    acceralateIO(0);

    int M, N;
    string str;
    cin >> M >> N;

    /* 利用 deque 維持目前考慮的 M 個數字 (後進前出)。
       利用 unordered_map 紀錄目前有幾種數字且分別有幾個 */
    deque<string> dq;    
    unordered_map<string, int> num2cnt;

    /* 先把前 M 個數字以字串形式輸入 */
    for (int i = 0; i < M && cin >> str; i++) {
        dq.push_back(str);

        if (!num2cnt.count(str))
            num2cnt.insert({str,0});
        num2cnt.at(str)++;
    }

    uint64_t ans = (num2cnt.size() != M) ? 0 : 1;
    for (int i = M; i < N && cin >> str; i++) {
        /* 先從尾端加入 */
        dq.push_back(str);
        if (!num2cnt.count(str))
            num2cnt.insert({str,0});
        num2cnt.at(str)++;
        
        /* 後從頭端移除 */
        num2cnt.at(dq.front())--;
        if (num2cnt.at(dq.front()) < 1)
            num2cnt.erase(dq.front());
        dq.pop_front();

        if (num2cnt.size() == M)
            ans++;
    }
    cout << ans << endl;
    return 0;
}