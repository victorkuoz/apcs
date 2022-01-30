/* APCS 2019-02-p3 函數運算式求值 */
#include <bits/stdc++.h>

using namespace std;

int func_f(void);
int func_g(void);
int func_h(void);

string str;
stringstream ss;

int get_parameter () {
    ss >> str;
    switch (str.at(0)) {
        case 'f' :
            return func_f();
        case 'g' :
            return func_g();
        case 'h' :
            return func_h();
        default :
            return stoi(str);
    }
    return 0;
}

/* f(x) = 2x - 3 */
int func_f (void) {
    int x = get_parameter();
    return (2*x -3);
}

/* g(x,y) = 2x + y – 7 */
int func_g (void) {
    int x = get_parameter();
    int y = get_parameter();
    return (2*x + y - 7);
}

/* h(x, y, z) = 3x – 2y + z */
int func_h (void) {
    int x = get_parameter();
    int y = get_parameter();
    int z = get_parameter();
    return (3*x - 2*y + z);
}

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /* 讀入整行並輸出至 ss 字串串流 */
    getline(cin, str);
    ss << str;

    cout << get_parameter() << endl;

    return 0;
}