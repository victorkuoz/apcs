/* APCS 2018-10-q2 子集合的和  */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int n, P, ans = 0;
vector<int> nums(0);

void subSetSum (int idx, int sum) {
    if (ans == P)
        return;
    
    if (idx < n) {
        subSetSum(idx+1, sum);
        sum += nums.at(idx);
        if (sum > P)
            return;
        if (sum > ans)
            ans = sum;
        subSetSum(idx+1, sum);
    }
    return;
}

int main () {
    acceralateIO(0);
    
    cin >> n >> P;
    for (int x, i = 0; i < n && cin >> x; i++)
        nums.push_back(x);

    sort(nums.begin(), nums.end());
    
    subSetSum(0, 0);

    cout << ans << endl;
    return 0;
}