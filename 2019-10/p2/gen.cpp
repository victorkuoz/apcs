#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2

void testcaseGenerator(fstream &file, int N, int M, int K) {
    file << N << " " << M << endl;
    for (int i = 0; i < N; i++)
        file << rand()%1000 << ((i == (N-1)) ? "\n" : " ");
    for (int i = 0; i < M; i++)
        file << rand()%K + 1 << ((i == (M-1)) ? "\n" : " ");
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, (rand()%10+1)*2, rand()%5+1, 1);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, (rand()%100+1)*2, rand()%10+1, 2);
        else
            testcaseGenerator(file, (rand()%1000+1)*2, rand()%100+1, 1000);
        file.close();
    }
    return 0;
}