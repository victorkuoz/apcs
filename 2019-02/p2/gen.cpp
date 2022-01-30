#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO (100/2)
#define N_ONE (10000/2)
#define N_TWO (1000000/2)


void testcaseGenerator(fstream &file, int N) {
    int M = rand()%(N/3) + (2*N/3);
    int K = rand()%(M/3) + (2*M/3);
    file << N << " " << K << endl;

    M -= K;
    bool *chosen = (bool*) calloc(N, sizeof(N));
    for (int i = 0, k = 0; i < M; i++, chosen[k] = true) {
        do
            k = (rand()%N);
        while (chosen[k]);
    }

    for (int i = 0; i < N; i++)
        file << (chosen[i] ? 1 : 0) << ((i != N-1) ? " " : "\n");
    
    for (int i = 0, k = 0; i < K; i++, chosen[k] = true) {
        do
            k = (rand()%N);
        while (chosen[k]);
        file << (k+1) << ((i != N-1) ? " " : "");
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