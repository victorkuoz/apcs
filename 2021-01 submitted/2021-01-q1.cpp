/* APCS 2021-01-q1 購買力 */
#include <iostream>

#define swap(a,b) {int tmp = a; a = b; b = tmp;}

using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    int x, y, z, cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        
        /* 使 x, y, z 由小排到大 */
        if (x > y)
            swap(x,y);
        if (y > z)
            swap(y,z);
        if (x > y)
            swap(x,y);
        
        /* 以平均價格購買 */
        if (d <= z-x) {
            cnt++;
            sum += (x+y+z)/3;
        }
    }
    cout << cnt << " " << sum;
    return 0;
}