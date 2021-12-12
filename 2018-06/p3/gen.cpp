#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define NMP_ZERO 10
#define NMP_ONE 100
#define NMP_TWO 500
#define T 100

void testcaseGenerator(fstream &file, int NMP) {
    int N = (rand()%NMP + 1), M = (rand()%NMP + 1);
    file << N << " " << M << endl;
    
    for (int i = 0; i < M; i++) {
        int P = (rand()%NMP +1);
        file << P << endl;
        for (int j = 0; j < P; j++)
            file << rand()%N << " " << (rand()%T + 1) << ((j != (P-1) ? " " : "\n"));
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, NMP_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, NMP_ONE);
        else
            testcaseGenerator(file, NMP_TWO);
        file.close();
    }
    return 0;
}