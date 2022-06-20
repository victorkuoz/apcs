#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2

int Ns[3] = {100/2, 1000/2, 1000000/2};
int Ds[3] = {10/2, 50/2, 100/2};

void testcaseGenerator(fstream &file, int N, int L, int R) {
    int P = rand()%N;
    file << N << " " << P << " " << L << " " << R << endl;

    vector<int> jumpTo(N);
    for (int i = 0; i < N; i++)
        jumpTo[i] = i;
    
    vector<int> dest_vec;
    for (int i = 0; i < N; i++)
        if (rand()%10 < 1)
            dest_vec.push_back(i);
    
    unordered_set<int> dest_set;
    dest_set.insert(dest_vec.begin(), dest_vec.end());
    
    for (int i = 0; i < N; i++) {
        if (dest_set.find(i) != dest_set.end())
            continue;
        
        if (rand()%10 < 2)
          jumpTo[i] = dest_vec[rand()%dest_vec.size()]; 
    }

    for (int i = 0; i < N; i++)
        file << jumpTo[i] << ((i != (N-1)) ? ' ' : '\n');
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%Ns[0] + Ns[0], rand()%Ds[0] + Ds[0], rand()%Ds[0] + Ds[0]);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%Ns[1] + Ns[1], rand()%Ds[1] + Ds[1], rand()%Ds[1] + Ds[1]);
        else
            testcaseGenerator(file, rand()%Ns[2] + Ns[2], rand()%Ds[2] + Ds[2], rand()%Ds[2] + Ds[2]);
        file.close();
    }
    return 0;
}