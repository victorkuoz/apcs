/* APCS 2021-01-q2 流量 */
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    /* 各伺服器至各城市之流量 */
    vector<vector<int>> server2city (N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> server2city.at(i).at(j);
    
    int x, ans = INT_MAX;
    vector<bool> chosen(M, false);
    vector<vector<int>> city2city (M, vector<int>(M, 0));
    
    for (int k = 0; k < K; k++) {
        /* 將 "各伺服器至各城市之流量" 轉成 "各城市至各城市之流量" */
        for (int i = 0; i < N; i++) {
            cin >> x;
            chosen.at(x) = true;
            for (int j = 0; j < M; j++)
                city2city.at(x).at(j) += server2city.at(i).at(j);
        }

        /* 針對有架設伺服器之城市計算費用 */
        int sum = 0;
        for (int i = 0; i < M; i++) {
            if (!chosen.at(i))
                continue;
            chosen.at(i) = false;
            for (int j = 0; j < M; city2city.at(i).at(j) = 0, j++) {
                if (ans <= sum)
                    continue;
                if (i != j) {
                    if (city2city.at(i).at(j) <= 1000)
                        sum += 3*city2city.at(i).at(j);
                    else
                        sum += 3000 + 2*(city2city.at(i).at(j)-1000);
                }
                else
                    sum += city2city.at(i).at(j);
            }
        }
        if (sum < ans)
            ans = sum;
    }

    cout << ans << endl;
    return 0;
}