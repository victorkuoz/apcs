#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 11
#define K 100

void f(fstream &file);
void g(fstream &file);
void h(fstream &file);

void nextFunc (fstream &file) {
    int k = rand()%3;
        if (k < 1)
            f(file);
        else if (k < 2)
            g(file);
        else
            h(file);
}

void f (fstream &file) {
    file << "f ";
    for (int i = 0; i < 1; i++) {
        if (rand()%2) {
            if (rand()%2)
                file << rand()%K << " ";
            else
                file << -(rand()%K) << " ";
        }
        else
            nextFunc(file);
    }
}

void g (fstream &file) {
    file << "g ";
    for (int i = 0; i < 2; i++) {
        if (rand()%2) {
            if (rand()%2)
                file << rand()%K << " ";
            else
                file << -(rand()%K) << " ";
        }
        else
            nextFunc(file);
    }
}

void h (fstream &file) {
    file << "h ";
    for (int i = 0; i < 3; i++) {
        if (rand()%2) {
            if (rand()%2)
                file << rand()%K << " ";
            else
                file << -(rand()%K) << " ";
        }
        else
            nextFunc(file);
    }
}

void testcaseGenerator(fstream &file) {
    nextFunc(file);
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