/* APCS 2016-03-q2 矩陣轉換 */
#include <iostream>

#define MAX_SIZE 10
#define swap(a,b) {int tmp = a; a = b; b = tmp;}

using namespace std;

void flip (int R, int C, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int r = 0; r < (R/2); r++)
        for (int c = 0; c < C; c++)
            swap(matrix[r][c], matrix[(R-1)-r][c]);
}

void rotate (int &R, int &C, int matrix[MAX_SIZE][MAX_SIZE]) {
    int duplication[R][C];
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            duplication[r][c] = matrix[r][c];
    
    swap(R,C);

    for (int i = 0, c = (R-1); i < R; i++, c--)
        for (int j = 0, r = 0; j < C; j++, r++)
            matrix[i][j] = duplication[r][c];
}

int main () {
    /* 加速讀寫 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C, M, cmds[MAX_SIZE], matrix[MAX_SIZE][MAX_SIZE];
    while ( cin >> R >> C >> M ) {
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                cin >> matrix[r][c];

        for (int i = 0; i < M; i++)
            cin >> cmds[i];
        for (int i = M; i > 0; i--) {
            if (cmds[i-1])
                flip(R, C, matrix);
            else
                rotate(R, C, matrix);
        }

        cout << R << " " << C << endl;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                cout << matrix[r][c] << ((c != (C-1)) ? ' ' : '\n');
    }
    return 0;
}