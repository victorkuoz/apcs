/* APCS 2017-10-q3 樹狀圖分析 */
#include <iostream>
#include <vector>

using namespace std;

uint64_t ans;
vector<vector<int>> adj_list(0);

/* 遞迴計算各節點之高度 */
uint64_t calculate_height (int idx) {
    uint64_t h, max = 0;
    /* 計算各子樹之高度並取最大值 */
    for (auto it = adj_list.at(idx).begin(); it != adj_list.at(idx).end(); it++) {
        h = calculate_height(*it);
        if (h > max)
            max = h;
    }
    ans += (max++);
    return max;
}

int main ( ) {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    vector<bool> hasParent(0);
    while (cin >> n) {
        ans = 0;
        hasParent.resize((n+1), false);
        adj_list.resize((n+1), vector<int>(0));
        
        for (int i = 1; i <= n && cin >> x; i++) {
            adj_list.at(i).resize(x);
            for (int j = 0; j < x && cin >> adj_list.at(i).at(j); j++)
                hasParent.at(adj_list.at(i).at(j)) = true;
        }
        
        /* 尋找根節點並開始遞迴 */
        for (int r = 1; r <= n; r++) {
            if(!hasParent.at(r)) {
                calculate_height(r);
                cout << r << endl << ans << endl;
                break;
            }
        }
        hasParent.clear();
    }
    return 0;
}