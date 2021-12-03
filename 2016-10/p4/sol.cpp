/* APCS 2016-10-p4 棒球比賽 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    int n,b,cnt=0,count=0,score=0;
    vector<vector<string>> data;

    for ( int i = 0; i < 9; i++ ) {
        scanf("%d", &n);
        vector<string> player;
        data.push_back(player);
        for ( int j = 0; j < n; j++ ) {
            string input;
            cin >> input;
            data.at(i).push_back(input);
        }
    }
    scanf("%d",&b);
     
    int hit;
    bool B1 = false, B2 = false, B3 = false;
    for(int i=0;i<5;i++) {
        for(int j=0;j<9;j++)
        {
            if (data.at(j).at(i) == "1B")
                hit = 1;
            else if (data.at(j).at(i) == "2B")
                hit  = 2;
            else if (data.at(j).at(i) == "3B")
                hit  = 3;
            else if (data.at(j).at(i) == "HR")
                hit  = 4;
            else
                hit = 0;
            
            switch (hit) {
                case 1 :
                    if (B3) {
                        score++;
                        B3 = false;
                    }
                    if (B2) {
                        B3 = true;
                        B2 = false;
                    }
                    if (B1)
                        B2 = true;
                    B1 = true;
                    break;
                case 2 :
                    if (B3) {
                        score++;
                        B3 = false;
                    }
                    if (B2)
                        score++;
                    if (B1) {
                        B3 = true;
                        B1 = false;
                    }
                    B2 = true;
                    break;
                case 3 :
                    if (B3)
                        score++;
                    if (B2) {
                        score++;
                        B2 = false;
                    }
                    if (B1) {
                        score++;
                        B1 = false;
                    }
                    B3 = true;
                    break;
                case 4 :
                    if (B3)
                        score++;
                    if (B2)
                        score++;
                    if (B1)
                        score++;
                    score++;
                    B1 = B2 = B3 = false;
                    break;
                default :
                    cnt++;
                    if (cnt%3 == 0)
                        B1 = B2 = B3 = false;
                    break;
            }

            if (cnt == b)   {
                printf("%d\n", score);
                return 0;
            }
        }
    }
    printf("%d\n",score);

    return 0;
}