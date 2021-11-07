/* APCS 2019-10-q2 洗牌 */
#include <iostream>
#include <vector>

using namespace std;

#define swap(a,b) { int c = a; a = b; b = c; }
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int pre = 0, cur = 1, N, M, k;
vector<int> cmds;
vector<vector<int>> cards(2, vector<int>(0));

void shuffle_back() {
    int half = (N/2);
    for (int p_idx = 1, c_idx = 1; p_idx <= half; p_idx++, c_idx += 2)
        cards.at(pre).at(p_idx) = cards.at(cur).at(c_idx);
    for (int p_idx = (half+1), c_idx = 2; p_idx <= N; p_idx++, c_idx += 2)
        cards.at(pre).at(p_idx) = cards.at(cur).at(c_idx);
}

void cut_back() {
    k %= N;
    for (int p_idx = 1, c_idx = (N-k+1); p_idx <= k; p_idx++, c_idx++)
        cards.at(pre).at(p_idx) = cards.at(cur).at(c_idx);
    for (int p_idx = (k+1), c_idx = 1; p_idx <= N; p_idx++, c_idx++)
        cards.at(pre).at(p_idx) = cards.at(cur).at(c_idx);
}

void reverseShuffle_back() {
    int half = (N/2);
    for (int p_idx = 1, c_idx = 1; p_idx <= N; p_idx += 2, c_idx++)
        cards.at(pre).at(p_idx) = cards.at(cur).at(c_idx);
    for (int p_idx = 2, c_idx = (half+1); p_idx <= N; p_idx += 2, c_idx++)
        cards.at(pre).at(p_idx) = cards.at(cur).at(c_idx);
}

int main () {
    acceralateIO(0);
    while (cin >> N >> M) {
        cmds.resize(M);
        cards.at(cur).resize(N+1);
        cards.at(pre).resize(N+1);

        for (int i = 1; i <= N; i++)
            cin >> cards.at(cur).at(i);

        for (int i = 0; i < M; i++)
            cin >> cmds.at(i);

        for (int i = (M-1); 0 <= i; i--) {
            k = cmds.at(i);
            switch (k) {
                case 1 :
                    shuffle_back();
                    break;
                case 2 :
                    reverseShuffle_back();
                    break;
                default:
                    cut_back();
                    break;
            }
            swap(pre, cur);
        }
        for (int i = 1; i <= N; i++) {
            if (i != 1)
                cout << " ";
            cout << cards.at(cur).at(i);
        }
        cout << endl;
    }
    return 0;
}