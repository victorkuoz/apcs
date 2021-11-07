/* APCS 2020-07-q3 圓環出口 */
#include <iostream>
#include <vector>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);

    int N, M;
    cin >> N >> M;

    /* 輸入並計算前序和 */
    vector<uint32_t> p(N), pre(N, 0);
    for (int i = 0; i < N && cin >> p.at(i); pre.at(i) += p.at(i), i++)
        if (i != 0)
            pre.at(i) += pre.at(i-1);
    
    /* 依序接受任務 */
    int m, c = 0;
    for (int i = 0; i < M && cin >> m; i++) {
        /* 加上 c 之前之前序和，模擬從 0 出發，目標為 (m + pre.at(c-1)) 之任務 */
        if (c != 0)
            m += pre.at(c-1);
        /* 若超出範圍則扣掉所有房間之總和 */
        if (m > pre.at(N-1))
            m -= pre.at(N-1);
        /* 利用 lower_bound 找出可達成需求之最小索引值房間並加一 */
        c = ((int) (lower_bound(pre.begin(), pre.end(), m) - pre.begin()) + 1)%N;
    }
    cout << c << endl;
    return 0;
}