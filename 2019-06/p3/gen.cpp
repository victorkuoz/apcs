#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define M_ZERO (10/2)
#define M_ONE (26/2)
#define M_TWO (52/2)
#define N_ZERO (10/2)
#define N_ONE (100/2)
#define N_TWO (800/2)
#define LEN 1000

void complementPairs(fstream &file, int M, int N, int n, bool *chosen) {
    string p(""), q("");

    for (int i = 0; i < M; i++) {
        if (chosen[i])
            p += ((i < 26) ? static_cast<char>('A'+i) : static_cast<char>('a'+i-26));
        else
            q += ((i < 26) ? static_cast<char>('A'+i) : static_cast<char>('a'+i-26));
    }

    for (int i = 0, L = 0; (i < n) && (p != ""); i++) {
        L = rand()%LEN;
        string input(p);
        for (int j = 0, len = input.length(); j < L; j++, len++)
            input.insert(rand()%len, 1, input.at(rand()%len));
        if (input != "")
            file << input << endl;
    }
    for (int i = 0, L = 0; (i < (N-n)) && (q != ""); i++) {
        L = rand()%LEN;
        string input(q);
        for (int j = 0, len = input.length(); j < L; j++, len++)
            input.insert(rand()%len, 1, input.at(rand()%len));
        if (input != "")
            file << input << endl;
    }
}

void testcaseGenerator(fstream &file, int M, int N) {
    file << M << " " << N*N << endl;

    for (int i = 0; i < N; i++) {
        bool *chosen = (bool*) calloc(M, sizeof(bool));
        for (int i = 0; i < M; i++)
            if (rand()%2)
                chosen[i] = true;
        if (rand()%2)
            complementPairs(file, M, N, 0, chosen);
        else
            complementPairs(file, M, N, rand()%N + 1, chosen);
        free(chosen);
    }
}

int main () {
    srand(time(NULL));
    
    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%M_ZERO + M_ZERO, rand()%N_ZERO + N_ZERO);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%M_ONE + M_ONE, rand()%N_ONE + N_ONE);
        else
            testcaseGenerator(file, rand()%M_TWO + M_TWO, rand()%N_TWO + N_TWO);
        file.close();
    }
    return 0;
}