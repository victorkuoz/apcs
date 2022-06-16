#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 11

void testcaseGenerator(fstream &file) {
    for (int i = 0; i < 2; i++) {
        int host = 0;
        for (int i = 0, k = 0; i < 4; i++, host += k) {
            k = (rand()%101);
            file << k << ((i != 3) ? " " : "\n");
        }

        while (true) {
            int guest = 0;
            string input = "";
            for (int i = 0, k = 0; i < 4; i++, guest += k) {
                k = (rand()%101);
                input +=  (to_string(k) + ((i != 3) ? " " : "\n"));
            }
            if (host != guest) {
                file << input;
                break;
            }
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
            testcaseGenerator(file);
        file.close();
    }
    return 0;
}