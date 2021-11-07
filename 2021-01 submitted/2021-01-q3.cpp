/* APCS 2021-01-q3 切割費用 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    /* 將切割點按切割順序排序 */
    int cut, idx;
    vector<int> input(N);
    while (cin >> cut >> idx)
        input.at(--idx) = cut;
    
    set<int> cuts = {0, L};
    uint64_t ans = 0;

    /* 從 set 中找出 "大於目前切割點的最小值" 以及 "小於目前切割點的最大值"，兩者相減，並將目前切割點加入 set */
    for (int i = 0; i < N; i++) {
        if (cuts.find(input.at(i)) != cuts.end())
            continue;
        
        ans += *(cuts.upper_bound(input.at(i))) - *(--cuts.lower_bound(input.at(i)));
        cuts.insert(input.at(i));
    }
    cout << ans << endl;
    return 0;
}