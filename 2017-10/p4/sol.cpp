/* APCS 2017-10-p4 物品堆疊 */
#include <bits/stdc++.h>

using namespace std;

/* 自定義結構，含重量(W)以及使用頻率(W)，過載 '<' 實現權重排序 */
struct Obj {
    int W, F;
    /* 權重排序 */
    bool operator < (const Obj &o) const { return (W*o.F) < (o.W*F); }
};

int main ( ) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string N, W, F;
    stringstream ss;
    vector<Obj> objects(0);
    
    while (getline(cin, N) && (n = stoi(N))) {
        ss.str("");
        ss.clear();
        objects.resize(n);

        /* 先整行讀入測資，並利用字串串流 ss 加速*/
        getline(cin, W);
        getline(cin, F);
        ss << (W + " " + F);
        for (int i = 0; i < n; i++)
            ss >> objects.at(i).W;
        for (int i = 0; i < n; i++)
            ss >> objects.at(i).F;
        sort(objects.begin(), objects.end());

        uint64_t w = 0, ans = 0;
        for (int i = 0; i < n; w += objects.at(i).W, i++)
            ans += (w*objects.at(i).F);
        cout << ans << endl;
    }
    return 0;
}