/* APCS 2017-03-p4 基地台 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> p;

bool check(int R) {
    int k = K, max = (-1);

    for (int i = 0; i < N; i++) {
        if (max < p.at(i)) {
            max = (p.at(i) + R);
            k--;
        }
        if (k < 0)
            return false;
    }
    return true;
}

/* binary search */
int binary_search (int x, int y) {
    if (y - x < 2) {
        if (y - x < 1)
            return check(x) ? x : 0;
        if (check(x))
            return x;
        return check(y) ? y : 0;
    }

    int m = (x+y)/2;
    if (check(m)) {
        int t = binary_search(x,m-1);
        return (t > 0) ? t : m;
    }
    return binary_search(m+1,y);
}

int linear_search() {
    int R = 1;
    while (!check(R))
        R++;
    return R;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> K) {
        p.resize(N);
        for (int i = 0; i < N; i++)
            cin >> p.at(i);
        sort(p.begin(), p.end());
        cout << binary_search(1, (p.back() - p.front())) << endl;
    }
    return 0;
}