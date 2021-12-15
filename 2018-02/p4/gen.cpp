#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N 1000
#define L_ZERO 10
#define L_ONE 1000
#define L_TWO 100000

void testcaseGenerator(fstream &file, int L) {
    int n = (rand()%N + 1);
    for (int i = 0, l = (rand()%L); i < n; i++) {
        file << (rand()%9 + 1);
        for (int j = 0; j < l; j++)
            file << rand()%10;
        file << endl;    
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, L_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, L_ONE);
        else
            testcaseGenerator(file, L_TWO);
        file.close();
    }
    return 0;
}