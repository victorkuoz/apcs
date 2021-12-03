/* APCS 2016-10-p2 最大和 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    /* store the number we choose in each row */
    vector<int> choices(0);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x, max = 0;
        for (int j = 0; j < M; j++) {
            cin >> x;
            /* find the max in each row */
            if (x > max)
                max = x;
        }
        sum += max;
        choices.push_back(max);
    }

    cout << sum << endl;

    string s;
    /* construct the output string */
    for (int i = 0; i < N; i++)
        if (!(sum%choices.at(i)))
            s += (to_string(choices.at(i)) + " ");

    /* use substr() to deal with the trailling space */
    if (s.size())
        cout << s.substr(0, s.size()) << endl;
    else
        cout << -1 << endl;
    return 0;
}