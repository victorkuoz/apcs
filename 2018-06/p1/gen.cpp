#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 11

vector<string> codes{"0 1 0 1", "0 1 1 1", "0 0 1 0", "1 1 0 1", "1 0 0 0", "1 1 0 0"};

void testcaseGenerator(fstream &file, int N) {
    for (int i = 0; i < N; i++) {
        int n = (rand()%100 + 1);
        file << n << endl;
        for (int j = 0; j < n; j++)
            file << codes.at(rand()%6) << endl;
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%100 + 1);
        file.close();
    }
    return 0;
}