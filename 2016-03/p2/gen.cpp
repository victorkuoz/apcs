#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 6

void testcaseGenerator(fstream &file, bool base) {
    int R = (rand()%10 + 1), C = (rand()%10 + 1), M = (rand()%10 + 1);
    file << R << " " << C << " " << M << endl;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            file << (rand()%10) << ((j != (C-1)) ? " " : "\n");

    if (base)
        for (int i = 0; i < M; i++)
            file << 1 << ((i != (M-1)) ? " " : "\n");
    else
        for (int i = 0; i < M; i++)
            file << (rand()%2) << ((i != (M-1)) ? " " : "\n");
}

int main () {
    srand(time(NULL));

    fstream file;
    bool base = true;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + static_cast<string>((i<10) ? "0" : "") + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, base);
        else
            testcaseGenerator(file, !base);
        file.close();
    }
    return 0;
}