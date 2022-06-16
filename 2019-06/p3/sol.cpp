/* APCS 2019-06-p3 互補CP */
#include <bits/stdc++.h>

using namespace std;

#define LEN 52
#define indexOf(c) ((c > 'Z') ? (c - 'a' + 26) : (c - 'A'))
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

typedef bitset<LEN> Bitset;

int main () {
    acceralateIO(0);

    int M, N;
    cin >> M >> N;
    cin.ignore();

    vector<Bitset> people(M, Bitset(1));
    for (int i = 1; i < M; i++)
        people.at(i) = (people.at(i-1) << 1);

    string str;
    vector<unordered_map<Bitset, int>> cps(M, unordered_map<Bitset, int>());
    for (int i = 0; i < N && getline(cin, str); i++) {
        Bitset cp(0);
        int cnt = 0, len = str.length();
        
        for (int j = 0; j < len; j++) {
            int idx = indexOf(str.at(j));
            if ((cp | people.at(idx)) != cp) {
                cp |= people.at(idx);
                cnt++;
            }
        }

        if (cnt < M) {
            if (!cps.at(cnt).count(cp))
                cps.at(cnt).insert({cp,0});
            cps.at(cnt).at(cp)++;
        }
    }

    /* 設定 mask */
    Bitset mask(0);
    for (int i = 0; i < M; i++)
        mask |= people.at(i);

    uint64_t ans = 0;
    for (int p = 1, q = (M-1); p <= q; p++, q--) {
        uint64_t sum = 0;
        for (auto it = cps.at(p).begin(); it != cps.at(p).end(); it++) {
            auto got = cps.at(q).find(mask ^ it->first);
            if (got != cps.at(q).end())
                sum += (it->second * got->second);
        }
        ans += (p != q) ? sum : (sum/2);
    }
    
    cout << ans << endl;
    return 0;
}