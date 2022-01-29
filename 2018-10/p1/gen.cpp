#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 11
#define N_ZERO (100/2)

void testcaseGenerator(fstream &file, int N) {
    file << N << endl;
    for (int i = 0; i < N; i++) {
        file << (rand()%10 + 1) << " ";
        for (int j = 0; j < 10; j++)
            file << rand()%100 << ((j != 9) ? " " : "\n");
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%N_ZERO + N_ZERO);
        file.close();
    }
    return 0;
}