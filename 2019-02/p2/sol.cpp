/* APCS 2019-02-p2 紅白彩帶 */
#include <bits/stdc++.h>

using namespace std;

/* (1) 另一端點之索引值 (若此處為紅色區間端點之一)
   (2) 此處之索引值 (若此處為非端點之紅色)
   (3) 0 (若此處為白色) */
vector<uint32_t> bound;

/* 映射 "紅色區間長度" 至 "此區間長度在彩帶中出現的次數" */
map<int, int> len2cnt;

/* 新增紅色區間至 len2cnt */
void add_interval (int p, int q) {
    int len = (q-p+1);

    /* p, q 互為對方之端點 */
    bound.at(p) = q;
    bound.at(q) = p;
    
    /* 更新 len2cnt */
    if (len2cnt.find(len) != len2cnt.end())
        len2cnt[len]++;
    else
        len2cnt[len] = 1;
    return;
}

/* 從 len2cnt 刪除紅色區間 */
void remove_interval (int len) {
    len2cnt[len]--;
    if (len2cnt[len] < 1)
        len2cnt.erase(len);
    return;
}

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    while (cin >> N >> K) {
        /* 清空 len2cnt 集合 */
        len2cnt.clear();
        /* 邏輯判斷上方便，故意多加入頭尾兩格代表白色 */
        bound.resize(N+2, 0);
        
        int x, p, q;
        for (q = 1; q <= N && cin >> x; q++) {
            bound.at(q) = (x) ? q : 0;
            
            if (!bound.at(q) && bound.at(q-1))
                add_interval(p, q-1);
            p = (!bound.at(q-1)) ? q : p;
        }
        /* 加入最後一個紅色區間 (如果存在) */
        if (bound.at(N))
            add_interval(p, N);
        
        /* 初始最短區間以及最長區間 */
        uint32_t m = len2cnt.begin()->first, M = (--len2cnt.end())->first;
        uint32_t M_sum = M, m_sum = m;
        
        for (int i = 0; i < K && cin >> x; M_sum += M, m_sum += m, i++) {
            int l = bound.at(x-1) ? bound.at(x-1) : x;
            int r = bound.at(x+1) ? bound.at(x+1) : x;

            if (l != x)
                remove_interval(x-l);
            if (r != x)
                remove_interval(r-x);
            add_interval(l,r);

            if ((r-l+1) > M)
                M = (r-l+1);
            m = len2cnt.begin()->first;
        }
        cout << M_sum << endl << m_sum << endl;
    }
    return 0;
}