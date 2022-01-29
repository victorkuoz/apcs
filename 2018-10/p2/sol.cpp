/* APCS 2018-10-p2 子集合的和  */
#include <bits/stdc++.h>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int N, P, ans;
vector<int> nums(0), suffixSum(0);

void subSetSum (int idx, int sum) {
    if (idx < N && (suffixSum.at(idx) > (ans - sum)) && ans < P) {
        int nextSum = (sum + nums.at(idx));
        if (nextSum < P)
            subSetSum(idx+1, nextSum);
        else if (nextSum > P)
            ans = (sum > ans) ? sum : ans;
        else
            ans = P;
        subSetSum(idx+1, sum);
    }
    else if (sum > ans)
        ans = sum;
}

int main () {
    acceralateIO(0);

    while (cin >> N >> P) {
        ans = 0;
        nums.resize(N);
        for (int i = 0; i < N; i++)
            cin >> nums.at(i);
        sort(nums.begin(), nums.end(), greater<int>());
    
        suffixSum.resize(N+1, P);
        suffixSum.at(N) = 0;
        for (int i = (N-1); i > (-1); i--) {
            suffixSum.at(i) = nums.at(i) + suffixSum.at(i+1);
            if (suffixSum.at(i) > P)
                break;
        }
        subSetSum(0, 0);
        cout << ans << endl;
    }
    return 0;
}