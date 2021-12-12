#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 7
#define NORMAL_NUM 100
#define MAX_NUM 10000

void testcaseGenerator(fstream &file, int N) {
    bool chosen[N];
    for (int i = 0; i < N; i++)
        chosen[i] = false;

    file << N << endl;
    for (int i = 0, id = 0; i < N; i++) {
        do {
            id = rand()%N;
        } while(chosen[id]);
        chosen[id] = true;
        file << id << ((i != (N-1)) ? " " : "");
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, rand()%NORMAL_NUM + 1);
        else
            testcaseGenerator(file, rand()%MAX_NUM + 1);
        file.close();
    }
    return 0;
}