#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ONE 7
#define LEVEL_TWO 2
#define LEVEL_THREE 2

void testcaseGenerator(fstream &file, int N, int range) {
    int K = rand()%(N/3) + (N/3);
    
    file << N << " " << K << endl;
    for (int i = 0; i < N; i++)
            file << rand()%range << ((i != (N-1)) ? " " : "\n");
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ONE)
            testcaseGenerator(file, (rand()%100 + 1), 1000);
        else if (i < LEVEL_ONE + LEVEL_TWO)
            testcaseGenerator(file, (rand()%10000 + 1), 1000000);
        else
            testcaseGenerator(file, (rand()%1000000 + 1), 1000000000);
        file.close();
    }
    return 0;
}