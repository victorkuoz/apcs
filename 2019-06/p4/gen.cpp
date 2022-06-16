#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2
#define M_ZERO (10/2)
#define M_ONE (100/2)
#define M_TWO (1000/2)
#define N_ZERO (100/2)
#define N_ONE (10000/2)
#define N_TWO (900000/2)

string randomInt (void) {
    int L = rand()%150;
    string Int = to_string(rand()%9 + 1);
    for (int i = 0; i < L; i++)
        Int += to_string(rand()%10);
    return Int;
}

void testcaseGenerator(fstream &file, int M, int N) {
    file << M << " " << N << endl;

    M = M*M/2;
    unordered_set<string> Ints;
    for (int i = 0; i < M; i++) {
        string Int;
        do 
            Int = randomInt();
        while (Ints.count(Int));
        Ints.insert(Int);
    }

    vector<string> candidates;
    for (string Int : Ints)
        candidates.push_back(Int);

    for (int i = 0; i < N; i++)
        file << candidates.at(rand()%M) << ((i != (N-1)) ? " " : "\n");
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