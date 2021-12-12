#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 7
#define NORMAL_NUM 5
#define MAX_NUM 50

void testcaseGenerator(fstream &file, int N) {
    file << N << endl << rand()%4 << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file << rand()%10 << ((j != (N-1)) ? " " : "\n");
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, (rand()%NORMAL_NUM)*2 + 1);
        else
            testcaseGenerator(file, (rand()%MAX_NUM)*2 + 1);
        file.close();
    }
    return 0;
}