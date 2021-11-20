#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 5
#define NUM_OF_MEDIUM_TESTCASE 3 

void testcaseGenerator(fstream &file, int flag) {
    int n = (flag < 2) ? (rand()%100 + 1) : (rand()%10000 + 1);
    file << n << endl;

    int range = (flag < 1) ? (1000/n) : (flag < 2) ? 10000 : 10000000;
    for (int i = 0, bound = 0; i < n; i++) {
        int p = (rand()%range + bound), q = (rand()%range + bound);
        file << min(p,q) << " " << max(p,q) << endl;
        if (flag < 1)
            bound += range;
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + static_cast<string>((i<10) ? "0" : "") + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, 0);
        else if (i < NUM_OF_BASE_TESTCASE + NUM_OF_MEDIUM_TESTCASE)
            testcaseGenerator(file, 1);
        else
            testcaseGenerator(file, 2);
        file.close();
    }
    return 0;
}