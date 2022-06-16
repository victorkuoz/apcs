/* APCS 2019-06-p2 機器人的路徑 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid((N+2), vector<int>((M+2),(-1)));

    int R, C;
    uint64_t ANS = INT_MAX;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> grid.at(i).at(j);
            if ((-1) < grid.at(i).at(j) && grid.at(i).at(j) < ANS) {
                R = i;
                C = j;
                ANS = grid.at(i).at(j);
            }
        }
    }
    
    vector<int> dr {-1, 1, 0, 0}, dc {0, 0, -1, 1};
    while (true) {
        int r, c, min = INT_MAX;
        for (int i = 0; i < 4; i++) {
            if (grid.at(R+dr[i]).at(C+dc[i]) < 0)
                continue;
            if (grid.at(R+dr[i]).at(C+dc[i]) < min) {
                r = (R+dr[i]);
                c = (C+dc[i]);
                min = grid.at(R+dr[i]).at(C+dc[i]);
            }
        }

        if (min == INT_MAX)
            break;
        grid.at(R).at(C) = (-1);
        R = r;
        C = c;
        ANS += min;
    }

    cout << ANS << endl;

    return 0;
}