/* APCS 2016-03-q4 血緣關係 */
#include <iostream>
#include <vector>

using namespace std;

int n;
int ans;
vector<vector<int>> grid(100000);

int DFS (int cur) {
    int size = grid.at(cur).size();
    
    if (size < 1)
        return 0;
    
    if (size < 2)
        return ( DFS(grid.at(cur).at(0)) + 1 );

    int max = 0, sec_max = 0, tmp;
    for (int i = 0; i < size; i++) {
        tmp = ( DFS(grid.at(cur).at(i)) + 1 );

        if (tmp >= max) {   // can't use >
            sec_max = max;
            max = tmp;
        }
        else if ( tmp > sec_max )
            sec_max = tmp;
    }
    
    if (max + sec_max > ans)
        ans = (max + sec_max);
    
    return max;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> ischild(100000);
    while (cin >> n) {
        ans = 0;

        /* clear the adjacency-list */
        for (int i = 0; i < n; i++ ) {
            grid.at(i).clear();
            ischild.at(i) = false;
        }
        
        /* read (n-1) edges */
        for (int p, c, i = 0; i < (n-1); i++) {
            cin >> p >> c;
            ischild[c] = true;
            grid.at(p).push_back(c);
        }

        int root = 0;
        for ( ; root < n; root++ ) {
            if (!ischild[root])
                break;
        }

        /* DFS from root */
        int len = DFS(root);

        if (len > ans)
            ans = len;
        cout << ans << endl;
    }
    return 0;
}