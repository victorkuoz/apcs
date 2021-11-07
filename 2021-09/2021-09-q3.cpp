/* APCS 2021-09-q3 幸運數字 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

struct Node {
    int val = 0, id = 0;

    bool operator > (const Node &n) const {return val > n.val;}
    bool operator < (const Node &n) const {return val < n.val;}
};

int main () {
    //acceralateIO(0);

    int n;
    cin >> n;

    vector<Node> nodes(n);
    vector<uint64_t> prefixSum(++n, 0);    

    for (int i = 1; i < n; i++) {
        nodes.at(i-1).id = i;
        cin >> nodes.at(i-1).val;
        prefixSum.at(i) += prefixSum.at(i-1) + nodes.at(i-1).val;
    }
    sort(nodes.begin(), nodes.end());
    
    int L = 1, R = (--n), idx = 0;
    while (L != R) {
        for ( ; idx < n; idx++)
            if (L <= nodes.at(idx).id && nodes.at(idx).id <= R)
                break;
        int M = nodes.at(idx).id, P = (M-1), Q = (M+1);

        uint64_t left = (P < L) ? 0 : prefixSum.at(P) - prefixSum.at(L-1);
        uint64_t right = (R < Q) ? 0 : prefixSum.at(R) - prefixSum.at(Q-1);

        if (left > right)
            R = P;
        else
            L = Q;
    }

    cout << prefixSum.at(L) - prefixSum.at(L-1) << endl;
    return 0;
}