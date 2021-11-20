/* APCS 2016-03-p3 線段覆蓋長度 */
#include <bits/stdc++.h>

using namespace std;

struct Segment {
    int L, R;

    friend istream &operator >> (istream &input, Segment &s) {
        input >> s.L >> s.R;
        return input;
    }

    bool operator< (const Segment& s) const {
        if (this->L != s.L)
            return this->L < s.L;
        return this->R < s.R;
    }
};

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Segment> segs(n);
    for (int i = 0; i < n; i++)
        cin >> segs.at(i);
    sort(segs.begin(), segs.end());

    int ans = 0, R = (-1);
    for (int i = 0; i < n; i++) {
        if (segs.at(i).R < R)
            continue;
        ans += segs.at(i).R - ((R > segs.at(i).L) ? R : segs.at(i).L);
        R = segs.at(i).R;   // Not Increment
    }
    cout << ans << endl;
    return 0;
}