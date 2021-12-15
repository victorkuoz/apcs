/* APCS 2018-02-p4 階梯數字 */
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int maxL = 0;
vector<vector<int>> dp(9, vector<int>(0));
void construction() {
    for (int d = 0; d < 9; d++)
        dp.at(d) = vector<int>(maxL, 1);
    for (int l = 1; l < maxL; l++)
        for (int d = 7; d > (-1); d--)
            dp[d][l] = ((dp[d+1][l] + dp[d][l-1]) % MOD);
    /*
    for (int d = 0; d < 9; d++)
        for (int l = 0; l < maxL; l++)
            cout << dp.at(d).at(l) << ((l != (maxL-1)) ? " " : "\n");
    */
}

int main () {
    acceralateIO(0);

    string input;
    vector<string> inputs;
    while (cin >> input) {
        inputs.push_back(input);
        if (input.length() > maxL)
            maxL = input.length();
    }
    construction();

    for (string N : inputs) {
        int ans = 1, L = N.length();
        for (int l = 1; l < L; l++) {
            ans += dp.at(0).at(l);
            if (ans > MOD)
                ans %= MOD;
        }
        
        L++;
        N = "1" + N;
        for (int i = 1; i < L; i++) {
            int prev = (N.at(i-1) - '0'), cur = (N.at(i) - '0');
            if (cur < prev) {
                ans--;
                break;
            }

            for (int j = (prev-1); j < (cur-1); j++)
                ans = (ans + dp.at(j).at((L-i)-1)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}