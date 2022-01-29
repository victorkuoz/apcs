#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO (6/2)
#define N_ONE (10/2)
#define N_TWO (14/2)

void recursion (fstream &file, int depth, int N) {
    int K = (depth < N) ? 10 : 2;
    for (int i = 0; i < 4; i++) {
        int digit = (rand()%K);
        if (digit > 1)
            digit = 2;
        file << digit;
        if (digit > 1)
            recursion(file, ++depth, N);
    }
}

void testcaseGenerator(fstream &file, int N) {
    cout << N << endl;
    file << 2;
    recursion(file, 1, N);
    file << endl << (1 << N) << endl;
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