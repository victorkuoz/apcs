/* APCS 2017-03-q3 數字龍捲風 */
#include <iostream>
#include <vector>

using namespace std;

/* left, up, right, down */
vector<vector<int> > grid;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

void print_one_direction(int &r, int &c, int d, int len) {
    for (int i = 0; i < len; i++) {
        r += dr[d];
        c += dc[d];
        cout << grid.at(r).at(c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, d, r, c;
    cin >> n >> d;

    grid = vector<vector<int> >(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n && cin >> x; j++)
            grid.at(i).at(j) = x;
    
    r = c = (n/2);
    cout << grid.at(r).at(c);
    for (int len = 1; len < n; len++)
        for (int cnt = 0; cnt < 2; cnt++, d = (d+1)%4)
            print_one_direction(r, c, d, len);
    
    print_one_direction(r, c, d, n-1);
    cout << endl;
    return 0;
}