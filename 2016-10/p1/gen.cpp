#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 10
#define MAX_NUM_OF_INPUT 30
#define MAX_LENGTH 10000

void randomOutput (fstream &file, int a, int b, int c) {
    switch (rand()%6) {
        case 0 :
            file << a << " " << b << " " << c << endl;
            break;
        case 1 :
            file << a << " " << c << " " << b << endl;
            break;
        case 2 :
            file << b << " " << a << " " << c << endl;
            break;
        case 3 :
            file << b << " " << c << " " << a << endl;
            break;
        case 4 :
            file << c << " " << a << " " << b << endl;
            break;
        default :
            file << c << " " << b << " " << a << endl;
            break;
    }
}

void testcaseGenerator(fstream &file) {
    int n = (rand()%MAX_NUM_OF_INPUT + 1), a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++) {
        switch (rand()%4) {
            case 0 :
                a = (rand()%MAX_LENGTH + 1);
                b = (rand()%MAX_LENGTH + 1);
                c = (a + b + 1); 
                break;
            case 1 :
                a = (rand()%MAX_LENGTH + 1);
                b = (rand()%MAX_LENGTH + 1);
                c = static_cast<int>(floor(sqrt(a*a + b*b)));
                break; 
            case 2 :
                a = (rand()%MAX_LENGTH + 1);
                b = (rand()%MAX_LENGTH + 1);
                c = static_cast<int>(ceil(sqrt(a*a + b*b)));
                break;
            default :
                a = (rand()%100);
                if (a%2 != 1)
                    ++a;
                b = ((a*a-1)/2);
                c = (b + 1);
        }
        randomOutput(file, a, b, c);
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < NUM_OF_BASE_TESTCASE)
            testcaseGenerator(file);
        file.close();
    }
    return 0;
}