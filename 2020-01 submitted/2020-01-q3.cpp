/* APCS 2020-01-q3 砍樹 */
#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

int main () {
    acceralateIO(0);
    int N, L;
    cin >> N >> L;

    vector<int> C(N+2, 0);
    for (int i = 1; i <= N; i++)
        cin >> C.at(i);
    C.at(N+1) = L;
    
    vector<int> H(N+2, INT_MAX);
    for (int i = 1; i <= N; i++)
        cin >> H.at(i);

    int cnt = 0, Max = 0;
    stack<int> stk;
    stk.push(0);

    for (int i = 1; i <= N; i++) {
        while (C.at(stk.top()) + H.at(stk.top()) <= C.at(i)) {
            Max = max(Max, H.at(stk.top()));
            stk.pop();
            cnt++;
        }

        if (C.at(stk.top()) <= (C.at(i) - H.at(i)) || (C.at(i) + H.at(i)) <= C.at(i+1)) {
            Max = max(Max, H.at(i));
            cnt++;
        }
        else
            stk.push(i);
    }
    cout << cnt << "\n" << Max << "\n";
    return 0;
}