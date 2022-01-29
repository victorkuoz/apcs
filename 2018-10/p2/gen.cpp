#include <bits/stdc++.h>

using namespace std;

#define P 1000000009
#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO (10/2)
#define N_ONE (100/2)
#define N_TWO (1000/2)


void testcaseGenerator(fstream &file, int N) {
    for (int i = 0; i < N; i++) {
        file << N << " " << P << endl;
        for (int i = 0, range = (P/N)*2; i < N; i++)
            file << (rand()%range + 1) << ((i != (N-1)) ? " " : "\n");
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
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%N_ONE + N_ONE);
        else
            testcaseGenerator(file, rand()%N_TWO + N_TWO);
        file.close();
    }
    return 0;
}