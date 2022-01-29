#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO (5/2)
#define N_ONE (30/2)
#define N_TWO (100/2)
#define M_ZERO (1000/2)
#define M_ONE (10000/2)
#define M_TWO (200000/2)

void testcaseGenerator (fstream &file, int N, int M) {
    int sum = 0;
    string input = "";
    for (int i = 0, k = 0; i < N; i++, sum += k) {
        k = rand()%(2*M/N);
        input += (to_string(k) + " ");
    }

    if (sum > M)
        M = sum;
    file << N << " " << M << " " << ((M/2) + rand()%(M/2)) << endl << input;
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%N_ZERO + N_ZERO, rand()%M_ZERO + M_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%N_ONE + N_ONE, rand()%M_ONE + M_ONE);
        else
            testcaseGenerator(file, rand()%N_TWO + N_TWO, rand()%M_TWO + M_TWO);
        file.close();
    }
    return 0;
}