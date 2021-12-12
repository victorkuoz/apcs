#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO 1000
#define N_ONE 10000
#define N_TWO 300000
#define K 1000000

void testcaseGenerator(fstream &file, int N) {
    file << N << endl;
    
    for (int i = 0; i < N; i++)
        file << rand()%K << ((i != (N-1) ? " " : "\n"));
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%N_ZERO+1);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%N_ONE+1);
        else
            testcaseGenerator(file, rand()%N_TWO+1);
        file.close();
    }
    return 0;
}