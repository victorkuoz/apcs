#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2

int Ds[3] = {10/2, 30/2, 70/2};

void testcaseGenerator(fstream &file, int M, int N) {
    file << M << " " << N << endl;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            file << rand()%2 << ((j != (N-1)) ? " " : "\n");
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
            testcaseGenerator(file, rand()%Ds[0] + Ds[0], rand()%Ds[0] + Ds[0]);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%Ds[1] + Ds[1], rand()%Ds[1] + Ds[1]);
        else
            testcaseGenerator(file, rand()%Ds[2] + Ds[2], rand()%Ds[2] + Ds[2]);
        file.close();
    }
    return 0;
}