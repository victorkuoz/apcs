#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define K_ZERO (10/2)
#define K_ONE (100/2)
#define K_TWO (1000/2)

void testcaseGenerator(fstream &file, int K) {
    int N = (rand()%K + K);
    for (int i = 0; i < N; i++) {
        int L = (rand()%K + 1), A[L], B[L];
        bool chosen[L] = {false};

        for (int n, j = 0; j < L; j++) {
            do  n = rand()%L;   while (chosen[n]);
            chosen[n] = true;
            A[j] = ++n;
        }

        for (int num = 1; num <= L; num++) {
            int cnt = 0;
            for (int j = 0; j < L; j++) {
                if (A[j] > num)
                    cnt++;
                else if (A[j] < num)
                    continue;
                else
                    break;
            }
            file << cnt << ((num != L) ? " " : "\n");
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
            testcaseGenerator(file, K_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, K_ONE);
        else
            testcaseGenerator(file, K_TWO);
        file.close();
    }
    return 0;
}