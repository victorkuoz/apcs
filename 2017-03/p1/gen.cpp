#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 7
#define NORMAL_LENGTH 9
#define MAX_LENGTH 1000

void testcaseGenerator(fstream &file, int length) {
    file << (rand()%9 + 1);
    for (int i = 1; i < length; i++)
        file << rand()%10;
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, rand()%NORMAL_LENGTH + 1);
        else
            testcaseGenerator(file, rand()%MAX_LENGTH + 1);
        file.close();
    }
    return 0;
}