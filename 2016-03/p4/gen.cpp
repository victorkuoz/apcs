#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 5
#define NUM_OF_MEDIUM_TESTCASE 3 

void testcaseGenerator(fstream &file, int flag) {
    int n = (flag < 1) ? (rand()%100 + 1) :
            (flag < 2) ? (rand()%2000 + 1) : (rand()%100000 + 1);
    file << n << endl;

    vector<bool> chosen(n, false);
    for (int i = 0, parent , child; i < (n-1); i++) {
        do
            parent = (rand()%n);
        while (i != 0 && !chosen.at(parent));
        chosen.at(parent) = true;

        do
            child = (rand()%n);
        while (chosen.at(child));
        chosen.at(child) = true;

        file << parent << " " << child << endl;
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
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