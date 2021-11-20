#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 5

void testcaseGenerator(fstream &file, int flag) {
    int n = (rand()%20 + 1);
    file << n << endl;

    switch (flag) {
        case (-1) :
            for (int i = 0; i < n; i++)
                file << rand()%101 << ((i != (n-1) ? " " : ""));
            break;
        case 0 :
            for (int i = 0; i < n; i++)
                file << (rand()%41 + 60) << ((i != (n-1) ? " " : ""));
            break;
        case 1 :
            for (int i = 0; i < n; i++)
                file << (rand()%60) << ((i != (n-1) ? " " : ""));
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + static_cast<string>((i<10) ? "0" : "") + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file, (-1));
        else {
            if (rand()%2)
                testcaseGenerator(file, 0);
            else
                testcaseGenerator(file, 1);
        }
        file.close();
    }
    return 0;
}