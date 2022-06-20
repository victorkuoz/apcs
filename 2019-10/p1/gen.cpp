#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 11

void testcaseGenerator(fstream &file) {
    int len = rand() % 1000 + 3;

    for (int i = 0; i < len; i++)
        file << rand() % 1000 << " ";
    file << rand() % 1000 << endl;
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file);
        file.close();
    }
    return 0;
}