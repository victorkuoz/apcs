/* APCS 2020-10-q2 人口遷移 */
#include <iostream>
#include <sstream>
#include <climits>
#include <vector>
using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* 跳過行尾換行 */
    int R, C, K, M;
    cin >> R >> C >> K >> M;
    cin.ignore();

    /* 預先讀取所有輸入，並導向字串串流 */
    string str;
    stringstream ss;
    for (int i = 0; i < R && getline(cin, str); i++, ss << " ")
        ss << str;

    /* 將字串串流導向 grid */
    vector<vector<int>> grid(R+2, vector<int>(C+2,-1));
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            ss >> grid.at(i).at(j);

    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
    vector<vector<int>> delta(R+2, vector<int>(C+2,0));
    for (int m = 0; m < M; m++) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (grid.at(i).at(j) < 0)
                    continue;
                int minus = 0, add = (grid.at(i).at(j)/K);
                for (int k = 0; k < 4; k++) {
                    int r = (i+dr[k]), c = (j+dc[k]);
                    if (0 <= grid.at(r).at(c)) {
                        delta.at(r).at(c) += add;
                        minus -= add;
                    }
                }
                delta.at(i).at(j) += minus;
            }
        }

        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                if (0 <= grid.at(i).at(j)) {
                    grid.at(i).at(j) += delta.at(i).at(j);
                    delta.at(i).at(j) = 0;
                }
    }
    
    /* 找出 "最多人" 以及 "最少人" 之城市 */
    int min = INT_MAX, max = 0; 
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (grid.at(i).at(j) < 0)
                continue;
            if (grid.at(i).at(j) < min)
                min = grid.at(i).at(j);
            if (grid.at(i).at(j) > max)
                max = grid.at(i).at(j);
        }
    }
    cout << min << endl << max << endl;
    return 0;
}