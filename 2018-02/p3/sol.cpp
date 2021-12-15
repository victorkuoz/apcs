/* APCS 2018-02-p3 支點切割 */
#include <bits/stdc++.h>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int N, K, sum = 0, ans = 0, MAXD = 0;
vector<int> prefixSum, suffixSum;

void cutting (int D, int L, int R) {
    if (D > MAXD)
        MAXD = D;
    if ((D > K) || ((R - L + 1) < 3))
        return;
    
    int M = (R+L)/2, cut = M;
    long long leftLeverage = 0, rightLeverage = 0;
    for (int i = L; i < M; i++)
        leftLeverage += (prefixSum.at(i) - prefixSum.at(L-1));
    for (int i = (M + 1); i < (R+1); i++)
        rightLeverage += (suffixSum.at(i) - suffixSum.at(R+1));
    long long min = abs(leftLeverage - rightLeverage);

    if (leftLeverage > rightLeverage) {
        for (int c = (M-1); c > L && (leftLeverage > rightLeverage); c--) {
            leftLeverage -= (prefixSum.at(c) - prefixSum.at(L-1));
            rightLeverage += (suffixSum.at(c+1) - suffixSum.at(R+1));

            long long diff = abs(leftLeverage - rightLeverage);
            if (diff < min) {
                min = diff;
                cut = c;
            }
        }
    }
    else {
        for (int c = (M+1); c < R && (leftLeverage < rightLeverage); c++) {
            leftLeverage += (prefixSum.at(c-1) - prefixSum.at(L-1));
            rightLeverage -= (suffixSum.at(c) - suffixSum.at(R+1));

            long long diff = abs(leftLeverage - rightLeverage);
            if (diff < min) {
                min = diff;
                cut = c;
            }
        }
    }

    cutting(D+1, L, cut-1);
    cutting(D+1, cut+1, R);
    ans += (prefixSum.at(cut) - prefixSum.at(cut-1));
}

int main () {
    acceralateIO(0);
    cin >> N >> K;

    prefixSum = vector<int>(N+2, 0);
    suffixSum = vector<int>(N+2, 0);
    
    for (int i = 1, x; cin >> x; i++)
        prefixSum.at(i) = (sum += x);
    for (int i = 1; i < (N+1); i++)
        suffixSum.at(i) = sum - prefixSum.at(i-1);
    cutting(1, 1, N);
    cout << ans;
    return 0;
}