#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define W_ZERO (10/2)
#define W_ONE (100/2)
#define W_TWO (3000/2)

void testcaseGenerator(fstream &file, int N, int M) {
    file << N << " " << M << endl;

    bool *chosen = new bool[N*M];
    for (int i = 0, k = 0, K = N*M; i < N; i++) {
        for (int j = 0; j < M; j++) {
            do
                k = rand()%K;
            while (chosen[k]);
            chosen[k] = true;
            file << (k+1) << ((j != (M-1)) ? " " : "\n");
        }
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%W_ZERO + W_ZERO, rand()%W_ZERO + W_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%W_ONE + W_ONE, rand()%W_ONE + W_ONE);
        else
            testcaseGenerator(file, rand()%W_TWO + W_TWO, rand()%W_TWO + W_TWO);
        file.close();
    }
    return 0;
}