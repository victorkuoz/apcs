/* APCS 2019-10-q3 闖關路線 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);

    int N, P, L, R;
    queue<int> que;
    vector<int> dests(0);
    vector<int> dists(0);

    while (cin >> N >> P >> L >> R) {
        while (!que.empty())
            que.pop();
        dests.resize(N);
        dists.assign(N,-1);
        
        for (int i = 0; i < N && cin >> dests.at(i); i++)
            if (dests.at(i) < 0 || N <= dests.at(i))
                dests.at(i) = N;
        
        que.push(0);
        dists.at(0) = 0;

        while (!que.empty() && dists.at(P) < 0) {
            int cur = que.front();
            que.pop();

            int next = (cur - L);
            if (0 < next && dests.at(next) != N && dists.at(dests.at(next)) < 0) {
                dists.at(dests.at(next)) = dists.at(cur) + 1;
                que.push(dests.at(next));
            }
            next = (cur + R);
            if (next < N && dests.at(next) != N && dists.at(dests.at(next)) < 0) {
                dists.at(dests.at(next)) = dists.at(cur) + 1;
                que.push(dests.at(next));
            }
        }
        cout << dists.at(P) << endl;
    }
    return 0;
}