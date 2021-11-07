/* APCS 2017-03-q1 秘密差 */
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    string input;
    int odd=0,even=0;

    getline(cin, input);
    for (int i = 0, len = input.length(); i < len; i += 2)
        odd += (input.at(i) - '0');
    for (int i = 1, len = input.length(); i < len; i += 2)
        even += (input.at(i) - '0');
    cout << abs(odd-even) << endl;
    return 0;
}