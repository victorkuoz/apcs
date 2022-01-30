#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 11
#define M_ZERO (1000/2)


void testcaseGenerator(fstream &file, int M) {
    file << M << " " << (rand()%3 + 1) << endl;
    for (int i = 0; i < M; i++)
        file << (rand()%M) + 1 << " ";
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%M_ZERO + M_ZERO);
        file.close();
    }
    return 0;
}