/* APCS 2017-03-q2 小群體 */
#include <iostream>
#include <vector>

using namespace std;

int main () {
    /* accelerate I/O */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> f (n);

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        f.at(i) = x;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (f.at(i) != (-1)) {
            int idx = f.at(i);
            f.at(i) = (-1);

            while (f.at(idx) != (-1)) {
                idx = f.at(idx);
                f.at(idx) = (-1);
            }
            cnt++;
        }
    }
    
    cout << cnt << endl;

    return 0;
}