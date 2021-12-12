#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2

void testcaseGenerator (fstream &file, int N, int W, int F) {
    file << N << endl;
    for (int i = 0; i < N; i++)
        file << (rand()%W + 1) << ((i != (N-1)) ? " " : "\n");
    for (int i = 0; i < N; i++)
        file << (rand()%F + 1) << ((i != (N-1)) ? " " : "\n");
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%10 + 1, 10, 1);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%100 + 1, 100, 10);
        else
            testcaseGenerator(file, rand()%3000000 + 1, 1000, 100);
        file.close();
    }
    return 0;
}