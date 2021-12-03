/* APCS 2016-10-p3 定時 K 彈 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, M, K;
    cin >> N >> M >> K;

    int lucky = 0;
    for (int num = (N-K+1); num <= N; num++)
        lucky = ((lucky + M) % num);
    cout << (++lucky) << endl;

    return 0;
}