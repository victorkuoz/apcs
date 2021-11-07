/* APCS 2020-07-q4 病毒演化 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

#define INF (1e9)

int N, M;
vector <string> strs;
vector <vector <int> > adjlist;
vector <vector <vector <int> > > dp;
map<char, int> char2idx = {{'@', 0}, {'A', 1}, {'U', 2}, {'C', 3}, {'G', 4}};

void traverse (int cur, int pos) {
    /* strs.at(cur).at(pos) 之 "字元" 轉 "索引值" */
    int idx = char2idx.at(strs.at(cur).at(pos));
    
    /* 葉節點 */
    if (adjlist.at(cur).empty()) {
        if (idx < 1)
            for (int i = 0; i < 5; i++)
                dp.at(cur).at(pos).at(i) = 0;
        else
            dp.at(cur).at(pos).at(0) = dp.at(cur).at(pos).at(idx) = 0;
        return;
    }

    /* 遞迴向下計算 */
    for (int child : adjlist.at(cur))
        traverse(child, pos);

    /* strs.at(cur).at(pos) 非 '@' */
    if (idx != 0) {
        dp.at(cur).at(pos).at(idx) = 0;

        for (int child : adjlist.at(cur))
            dp.at(cur).at(pos).at(idx) += min(dp.at(child).at(pos).at(0)+1,
                                             dp.at(child).at(pos).at(idx));
        dp.at(cur).at(pos).at(0) = dp.at(cur).at(pos).at(idx);
        return;
    }

    /* 針對 strs.at(cur).at(pos) 計算填入不同 ch 時之最小值 */
    for (int ch = 1; ch < 5; ch++) {
        dp.at(cur).at(pos).at(ch) = 0;
        for (int child : adjlist.at(cur))
            dp.at(cur).at(pos).at(ch) += min(dp.at(child).at(pos).at(0)+1, dp.at(child).at(pos).at(ch));
    }

    dp.at(cur).at(pos).at(0) = min(min(dp.at(cur).at(pos).at(1), dp.at(cur).at(pos).at(2)),
                                   min(dp.at(cur).at(pos).at(3), dp.at(cur).at(pos).at(4)));
}

int main () {
    acceralateIO(0);
    cin >> N >> M;
    
    int root;
    strs.resize(N+1);
    adjlist.resize(N+1, vector<int>(0));
    dp.resize(N+1, vector<vector<int>>(M, vector<int>(5, INF)));
    for (int c, p, i = 0; i < N && cin >> c >> p; i++) {
        if (c != p)
            adjlist.at(p).push_back(c);
        else
            root = c;
        cin >> strs.at(c);
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        traverse(root, i);
        ans += dp.at(root).at(i).at(0);
    }
    
    cout << ans << endl;
    return 0;
}