#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO (100/2)
#define N_ONE (10000/2)
#define N_TWO (2000000/2)
#define K (10000)

void testcaseGenerator(fstream &file, int N) {
    file << N << endl;
    for (int i = 0; i < N; i++)
        file << (rand()%K + 1) << ((i != (N-1)) ? " " : "\n");
    for (int i = 0; i < N; i++)
        file << rand()%K << ((i != (N-1)) ? " " : "\n");
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%N_ZERO + N_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_TWO)
            testcaseGenerator(file, rand()%N_ONE + N_ONE);
        else
            testcaseGenerator(file, rand()%N_TWO + N_TWO);
        file.close();
    }
    return 0;
}