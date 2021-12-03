#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 11

void testcaseGenerator(fstream &file, int N, int M) {
    file << N << " " << M << endl;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            file << (rand()%127 + 1) << ((j != (M-1)) ? " " : "\n");
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, (rand()%20 + 1), (rand()%20 + 1));
        file.close();
    }
    return 0;
}