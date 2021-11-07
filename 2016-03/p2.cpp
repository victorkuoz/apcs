/* APCS 2016-03-q2 矩陣轉換 */
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void row_exchange(int **arr, int r, int c) {
    int tmp[c];

    for (int i = 0, j = (r-1); i < (r/2); i++, j--) {
        for (int k = 0; k < c; k++) {
            tmp[k] = arr[i][k];
            arr[i][k] = arr[j][k];
            arr[j][k] = tmp[k];
        }
    }
}

void column_exchange(int **arr, int r, int c) {
    int tmp[r];

    for (int i = 0, j = (c-1); i < (c/2); i++, j--) {
        for (int k = 0; k < r; k++) {
            tmp[k] = arr[k][i];
            arr[k][i] = arr[k][j];
            arr[k][j] = tmp[k];
        }
    }
}

#define max_size 10

int main() {
    int r, c, m, *arr[max_size];

    for (int i = 0; i < max_size; i++)
        arr[i] = new int[max_size];

    while ( scanf("%d %d %d", &r, &c, &m) != EOF ) {
        int s[m], cnt = 0;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                scanf("%d", &arr[i][j]);
    
        for (int i = (m-1); i >= 0; i--)
            scanf("%d", &s[i]);
        
        /* flip in different direction according to how many spin we take */
        for (int i = 0; i < m; i++) {
            if (s[i]) {
                if (cnt%2)  // cnt%2 != 0
                    column_exchange(arr, r, c);
                else
                    row_exchange(arr, r, c);
            }
            else
                cnt++;
        }

        if (cnt%2)
            printf("%d %d\n", c, r);
        else
            printf("%d %d\n", r, c);

        /* print in different order according to how many spin we take */
        switch (cnt%4) {
            case 0 :
                for(int i = 0; i < r; i++)
                    for(int j = 0; j < c; j++)
                        printf("%d%c",arr[i][j], j == (c-1) ? '\n' : ' ');
                break;
            case 1 :
                for(int i = (c-1); i >= 0; i--)
                    for(int j = 0; j < r; j++)
                        printf("%d%c",arr[j][i], j == (r-1) ? '\n' : ' ');
                break;
            case 2 :
                for(int i = (r-1); i >= 0; i--)
                    for(int j = (c-1); j >= 0; j--)
                        printf("%d%c",arr[i][j], j == 0 ? '\n' : ' ');
                break;
            default :
                for(int i = 0; i < c; i++)
                    for(int j = (r-1); j >= 0; j--)
                        printf("%d%c",arr[j][i], j == 0 ? '\n' : ' ');
                break;
        }
    }
    return 0;
}