#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO (100/2)
#define N_ONE (30000/2)
#define N_TWO (5000000/2)
#define K_ZERO (10/2)
#define K_ONE (20/2)
#define K_TWO (30/2)
#define R 10

void testcaseGenerator(fstream &file, int N, int K) {
    file << N << " " << K << endl;
    for (int i = 0; i < N; i++)
        file << (rand()%R + 1) << ((i != (N-1) ? " " : "\n"));
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%N_ZERO + N_ZERO, rand()%K_ZERO + K_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%N_ONE + N_ONE, rand()%K_ONE + K_ONE);
        else
            testcaseGenerator(file, rand()%N_TWO + N_TWO, rand()%K_TWO + K_TWO);
        file.close();
    }
    return 0;
}