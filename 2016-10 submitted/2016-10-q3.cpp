/* APCS 2016-10-q3 定時K彈 */
#include <stdio.h>
#include <vector>

using namespace std;

int main () {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<int> vec;
    for (int i = 0; i < n; i++ )
        vec.push_back(i+1);

    int x = (m-1);
    for ( int i = 0; i < k; i++ ) {
        if (x >= vec.size())
            x %= vec.size();
        vec.erase(vec.begin()+x);
        x += (m-1);
    }

    x -= (m-1);

    if (x >= vec.size())
        printf("%d\n", vec.at(0));  
    else
        printf("%d\n", vec.at(x));

    return 0;
}