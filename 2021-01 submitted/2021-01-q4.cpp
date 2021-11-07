/* APCS 2021-01-q4 飛黃騰達 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef struct point {
    int x, y;
} Point;

/* 先用 x 排序，然後 y */
struct cmp {
    bool operator() (Point a, Point b) {
        if (a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    }
};

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int X, Y;
    vector<Point> points(N);
    for (int i = 0; i < N; i++)
        cin >> points.at(i).x >> points.at(i).y;
    sort(points.begin(), points.end(), cmp());
    
    /* 針對 y 找出 points 的最長子遞增數列長度 */
    multiset<int> LIS;
    for (int i = 0; i < N; i++) {
        auto it = LIS.upper_bound(points.at(i).y);
        if (it != LIS.end())
            LIS.erase(it);
        LIS.insert(points.at(i).y);
    }

    cout << LIS.size() << endl;
    return 0;
}