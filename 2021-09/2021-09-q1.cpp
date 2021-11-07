/* APCS 2021-09-q1 七言對聯 */
#include <iostream>
#include <string>

using namespace std;

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    
    string p, q, output;
    for (int i = 0; i < n; i++) {
        getline(cin, p);
        getline(cin, q);

        output = "";
        if (p.at(2) == p.at(6) || p.at(2) != p.at(10) || q.at(2) == q.at(6) || q.at(2) != q.at(10))
            output += "A";
        if (p.at(12) != '1' || q.at(12) != '0')
            output += "B";
        if (p.at(2) == q.at(2) || p.at(6) == q.at(6) || p.at(10) == q.at(10))
            output += "C";
        if (output == "")
            output += "None";
        cout << output << endl;
    }
    return 0;
}