/* APCS 2019-02-q4 帶著板凳排雞排的高人 */
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

/* 自定義結構，含索引值(idx)以及身高(height)，
   過載 '<' 實現預設排序 */
struct People {
    int idx, height;
    People(int i, int h) : idx(i),height(h) {}
    /* 依據 height 遞增排序 */
    bool operator < (const People &p) const { return (height < p.height); }
};

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();

    /* 利用字串串流 ss 將字串(string)轉成整數(int) */
    string H, P;
    stringstream ss;
    getline(cin, H);
    getline(cin, P);
    ss << (H + " " + P);
    
    /* 將輸入存放至 vector */
    vector<int> h(N), p(N);
    for (int i = 0; i < N; i++)
        ss >> h.at(i);
    for (int i = 0; i < N; i++)
        ss >> p.at(i);

    /* 利用 set 維持至目前的遞減序列，
       然而是以嚴格遞增序列(SIS)的方式紀錄 */
    set<People> SIS;
    uint64_t ans = 0;
    SIS.insert(People(-1, 2e7+1));

    for (int i = 0; i < N; i++) {
        /* 從 SIS 找出高度大於 "h.at(i)+p.at(i)" 中且高度最矮的人 */
        People cur(i, h.at(i)+p.at(i));
        auto end = SIS.upper_bound(cur);
        
        /* 加上 i 可挑戰之人數 */
        ans += (i - end->idx - 1);
        
        /* 從 SIS 找出高度大於 "h.at(i)" 中且高度最矮的人 */
        cur.height -= p.at(i);
        end = SIS.upper_bound(cur);
        
        /* 移除所有高度小於等於 i 的人 */
        SIS.erase(SIS.begin(), end);
        
        /* 將 i 加至 SIS */
        SIS.insert(cur);
    }
    cout << ans << endl;
    return 0;
}