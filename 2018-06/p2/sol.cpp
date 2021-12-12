/* APCS 2018-06-p2 完全奇數 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    string s;
    int idx, size;

    while (cin >> s) {
        size = s.size();

        /* minK */
        string minK = s;
        for (idx = 0; idx < size; idx++)
            if ((minK.at(idx)-'0')%2 != 1)
                break;
        
        if (idx < size) {
            minK.at(idx)++;
            for (++idx; idx < size; idx++)
                minK.at(idx) = '1';
        }
        else {
            cout << 0 << endl;
            continue;
        }
        /* minK */
    
        /* maxK */
        string maxK = s;
        for (idx = 0; idx < size; idx++)
            if ((maxK.at(idx)-'0')%2 != 1)
                break;

        if (maxK.at(idx) != '0')
            maxK.at(idx)--;
        else {
            maxK.at(idx) = '9';
            
            int i = (idx-1);
            for ( ; i > 0; i--) {
                if (maxK.at(i) != '1') {
                    maxK.at(i) -= 2;
                    break;
                }
                else
                    maxK.at(i) = '9';
            }

            if (!i) {
                if (maxK.at(0) != '1')
                    maxK.at(0) -= 2;
                else
                    maxK.at(0) = '0';
            }
        }

        for (++idx; idx < size; idx++)
            maxK.at(idx) = '9';
        /* maxK */

        unsigned long long S = stoull(s), x = (stoull(minK) - S), y = (S - stoull(maxK));
        if (x < y)
            cout << x << endl;
        else
            cout << y << endl;
    }
    return 0;
}