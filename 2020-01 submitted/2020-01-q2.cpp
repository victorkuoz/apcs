/* APCS 2020-01-q2 矩陣總和 */
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int S, T, N, M, R;
vector<vector<int>> A, B;

int check (int x, int y) {
    int r = 0, a = 0, b = 0;
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < T; j++) {
            if (A.at(i).at(j) != B.at(i+x).at(j+y))
                r++;
            if (r > R)
                return (-1);
            a += A.at(i).at(j);
            b += B.at(i+x).at(j+y);
        }
    }
    return abs(a-b);
}

int main () {
    acceralateIO(0);
    cin >> S >> T >> N >> M >> R;

    /* 輸入 A 矩陣 */
    A.resize(S, vector<int>(T));
    for (int i = 0; i < S; i++)
        for (int j = 0; j < T; j++)
            cin >> A.at(i).at(j);
    
    /* 輸入 B 矩陣 */
    B.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B.at(i).at(j);
    
    int cnt = 0, min = INT_MAX;
    for (int i = 0; i < (N-S+1); i++) {
        for (int j = 0; j < (M-T+1); j++) {
            int tmp = check(i,j);
            /* 距離不超過 R */
            if ((-1) < tmp) {
                cnt++;
                if (tmp < min)
                    min = tmp;
            }
        }
    }
    
    cout << cnt << " ";
    if (min != INT_MAX)
        cout << min << endl;
    else
        cout << (-1) << endl;
    return 0;
}