#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 11

void testcaseGenerator(fstream &file) {
    file << (rand()%2 ? (rand()%100 + 1) : 0) << " "
         << (rand()%2 ? (rand()%100 + 1) : 0) << " "
         << rand()%2;
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