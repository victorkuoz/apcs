#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BASE_TESTCASE 11

vector<string> types { "HR",
                       "3B", "3B",
                       "2B", "2B", "2B",
                       "1B", "1B", "1B", "1B",
                       "FO", "FO", "FO", "FO", "FO",
                       "GO", "GO", "GO", "GO", "GO",
                       "SO", "SO" ,"SO", "SO", "SO"};

void testcaseGenerator(fstream &file) {
    vector<string> outcomes(0);
    int total_cnt = 0, out_cnt = 0;

    while (out_cnt < 27) {
        int n = (rand()%25);
        outcomes.push_back(types.at(n));
        if (n > 10)
            out_cnt++;
        total_cnt++;
    }

    int ave_cnt = (total_cnt/9), mod_cnt = (total_cnt%9);
    for (int i = 0 ; i < 9; i++) {
        int n = (i < mod_cnt) ? (ave_cnt + 1) : ave_cnt;
        
        file << n;
        for (int j = 0; j < n; j++)
            file << " " << outcomes.at(--total_cnt);
        file << endl;
    }
    file << (rand()%27 + 1);
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