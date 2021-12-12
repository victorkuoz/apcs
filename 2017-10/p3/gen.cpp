#include <bits/stdc++.h>

using namespace std;

#define LEVEL_ZERO 7
#define LEVEL_ONE 2
#define LEVEL_TWO 2

void testcaseGenerator(fstream &file, int N) {
    file << N << endl;

    int R = rand()%N;
    vector<int> nums(0), nodes(0);
    for (int i = 0; i < N; i++)
        nums.push_back(i);
    nums.erase(nums.begin() + R);
    nodes.push_back(R);
    
    vector<vector<int>> adjacency_list(N, vector<int>(0));
    for (int i = 1, size = nums.size(); i < N; i++, size--) {
        int p = nodes.at(rand()%i), c = nums.at(rand()%size);
        nums.erase(find(nums.begin(), nums.end(), c));
        adjacency_list.at(p).push_back(c);
        nodes.push_back(c);
    }

    for (int i = 0; i < N; i++) {
        file << adjacency_list.at(i).size();
        for (int c : adjacency_list.at(i))
            file << " " << (c+1);
        file << endl;
    }
}

int main () {
    srand(time(NULL));

    fstream file;
    for (int i = 0; i < 11; i++) {
        string name = "testcase/" + to_string(i) + ".in";
        file.open(name, ios::out);
        if (i < LEVEL_ZERO)
            testcaseGenerator(file, rand()%10 + 1);
        else if (i < LEVEL_ZERO + LEVEL_ONE)
            testcaseGenerator(file, rand()%1000 + 1);
        else
            testcaseGenerator(file, rand()%100000 + 1);
        file.close();
    }
    return 0;
}