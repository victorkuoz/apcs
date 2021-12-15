#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO (10/2)
#define N_ONE (100/2)
#define N_TWO (7000/2)
#define MOD 1000000009

void testcaseGenerator(fstream &file, int N) {
    N = (rand()%N + N);
    for (int i = 0; i < N; i++) {
        if (rand()%10 < 5)
            file << 1 << endl << (rand()%MOD + MOD) << endl;
        else {
            int L = (rand()%N + 1);
            file << L << endl;
            for (int i = 0; i < L; i++)
                file << (rand()%N + 1) << ((i != (L-1) ? " " : "\n"));
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
            testcaseGenerator(file, N_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, N_ONE);
        else
            testcaseGenerator(file, N_TWO);
        file.close();
    }
    return 0;
}