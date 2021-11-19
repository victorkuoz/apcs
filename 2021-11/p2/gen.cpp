#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 7

void testcaseGenerator(fstream &file, int n) {
    file << n << endl;
    for (int i = 0, pre = (-1); i < n; i++) {
        int cur = (rand()%100 + 1);
        if (pre)
            if (static_cast<double>(rand())/(RAND_MAX + 1.0) < 0.7)
                cur = 0;
        file << cur << ((i != (n-1)) ? " " : "");
        pre = cur;
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + static_cast<string>((i<10) ? "0" : "") + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, 3);
        else
            testcaseGenerator(file, (rand()%98)+3);
        file.close();
    }
    return 0;
}