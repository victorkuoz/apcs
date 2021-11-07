/* APCS 2021-09-q2 魔王迷宮 */
#include <iostream>
#include <vector>

using namespace std;

#define Empty 0
#define Exist 1
#define Countdown 2
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

class Monster {
public:
    int r, c, s, t;
    Monster *next = NULL;
    Monster() { cin >> this->r >> c >> s >> t; }
};

int n, m, k;
vector<vector<short>> *bombs;
Monster *check (Monster *cur) {
    if (cur != NULL) {
        cur->next = check(cur->next);
        if (cur->r < 0 || cur->r > (n-1) || cur->c < 0 || cur->c > (m-1))
            return cur->next;
        if (bombs->at(cur->r).at(cur->c) != Empty) {
            bombs->at(cur->r).at(cur->c) = Countdown;
            return cur->next;
        }
    }
    return cur;
}

int main () {
    acceralateIO(0);
    cin >> n >> m >> k;
    bombs = new vector<vector<short>>(n, vector<short>(m, Empty));
    
    Monster *monsters = new Monster(), *cur = monsters;
    for (int i = 1; i < k; i++, cur = cur->next)
        cur->next = new Monster();
    
    while (monsters != NULL) {
        for (cur = monsters; cur != NULL; cur = cur->next) {
            //cout << cur->r << " " << cur->c << endl;
            bombs->at(cur->r).at(cur->c) = Exist;
            cur->r += cur->s;
            cur->c += cur->t;
        }

        monsters = check(monsters);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                bombs->at(i).at(j) = (bombs->at(i).at(j) != Exist) ? Empty : Exist;
    }

    int ans = 0;
    for (vector<short> row : *bombs)
        for (short ch : row)
            if (ch != Empty)
                ans++;
    cout << ans << endl;
    return 0;
}