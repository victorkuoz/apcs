#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 6
#define NUM_OF_MEDIUM_TESTCASE 2
#define NUM_OF_HARD_TESTCASE 2

void testcaseGenerator(fstream &file, int flag) {
    int N, M;
    switch (flag) {
        case 0 :
            N = (rand()%static_cast<int>(1E2) + 1);
            M = (rand()%static_cast<int>(1E1) + 1);
            break;
        case 1 :
            N = (rand()%static_cast<int>(1E3) + 1);
            M = (rand()%static_cast<int>(1E3) + 1);
            break;
        case 2 :
            N = (rand()%static_cast<int>(1E4) + 1);
            M = (rand()%static_cast<int>(1E6) + 1);
            break;
        default :
            N = (rand()%static_cast<int>(1E8) + 1);
            M = static_cast<int>(2E9);
            break;
    }
    file << N << " " << M << " " << (rand()%(N+1) + 1);
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, 0);
        else if (i < NUM_OF_BASE_TESTCASE + NUM_OF_MEDIUM_TESTCASE)
            testcaseGenerator(file, 1);
        else if (i < NUM_OF_BASE_TESTCASE + NUM_OF_MEDIUM_TESTCASE + NUM_OF_HARD_TESTCASE)
            testcaseGenerator(file, 2);
        else
            testcaseGenerator(file, 3);
        file.close();
    }
    return 0;
}