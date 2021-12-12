#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define N_ZERO 10
#define N_ONE 100
#define N_TWO 1000

void testcaseGenerator(fstream &file, int K, int N, int L, int threshold) {
    file << K << endl;

    char ch = (rand()%2) ? 'A' : 'a';
    for (int i = 0, cnt = 1, len = 0; i < L; i++, cnt++) {
        if (cnt > len) {
            len = K;
            if (rand()%10 > threshold)
                len = (rand()%N+1);
            cnt = 1;
            ch = (ch != 'A') ? 'A' : 'a';
        }
        file << static_cast<char>(ch + rand()%26);
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%N_ZERO+1, N_ZERO, rand()%(N_ZERO*N_ZERO)+1, rand()%10);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%N_ONE+1, N_ONE, rand()%(N_ONE*N_ONE)+1, rand()%10);
        else
            testcaseGenerator(file, rand()%N_TWO+1, N_TWO, rand()%(N_TWO*N_TWO)+1, rand()%10);
        file.close();
    }
    return 0;
}