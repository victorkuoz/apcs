/* APCS 2020-10-q3 勇者修煉 */
#include <iostream>
#include <sstream>
#include <climits>
#include <vector>
using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N;
    cin >> M >> N;

    /* c.at(j), 針對特定列，位於 i 之值。
       l.at(j), 針對特定列，從左邊至 i 的最大值。
       r.at(j), 針對特定列，從右邊至 i 的最大值。
       dp.at(i).at(j)，至 (i,j) 的最大值。*/
    vector<int> c(N+2, 0), l(N+2, 0), r(N+2, 0);
    vector<vector<int>> dp((M+1), vector<int>(N+2, 0));

    /* 左右多留一格邊界設定為 INT_MIN */
    l.at(0) = l.at(N+1) = r.at(0) = r.at(N+1) = INT_MIN;
    
    /* 逐行輸入並計算 dp 值 */
    for (int i = 1; i <= M; i++) {
        /* 計算從左側至 j 之最大值 */
        for (int j = 1; j <= N && cin >> c.at(j); j++)
            l.at(j) = max(l.at(j-1), dp.at(i-1).at(j)) + c.at(j);
        /* 計算從右側至 j 之最大值 */
        for (int j = N; j > 0; j--)
            r.at(j) = max(r.at(j+1), dp.at(i-1).at(j)) + c.at(j);
        /* 計算至 dp.at(i).at(j) 之最大值 */
        for (int j = 1; j <= N; j++)
            dp.at(i).at(j) = max(l.at(j), r.at(j));
    }

    int ans = 0;
    for (int j = 1; j <= N; j++)
        if (dp.at(M).at(j) > ans)
            ans = dp.at(M).at(j);
    cout << ans << endl;
    return 0;
}