/* APCS 2019-10-q4 刪除邊界 */
#include <iostream>

using namespace std;

#define NotYet 625
#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

bool isOne[25][25];
uint16_t dpTable[25][25][25][25];

/* 計算移除 (r,c) 至 (R,C) 需要修改之次數 */
uint16_t numOfModification (int r, int c, int R, int C) {
    uint16_t one = 0, zero = 0;
    for (int i = r; i <= R; i++) for (int j = c; j <= C; j++) {
        if (isOne[i][j])
            one++;
        else
            zero++;
    }
    return min(one, zero);
}

uint16_t dp (int r, int c, int R, int C) {
    /* 若 dpTable[r][c][R][C] 已完成 */
    if (dpTable[r][c][R][C] != NotYet)
        return dpTable[r][c][R][C];

    /* 只剩一列或一行，可直接移除 */
    if ((R-r) < 1 || (C-c) < 1)
        return (dpTable[r][c][R][C] = 0);
    
    /* 移除"上"列 */
    dpTable[r][c][R][C] = numOfModification(r, c, r, C) + dp(r+1, c, R, C);
    
    /* 移除"下"列 */
    int cnt = numOfModification(R, c, R, C) + dp(r, c, R-1, C);
    if (cnt < dpTable[r][c][R][C])
        dpTable[r][c][R][C] = cnt;
    
    /* 移除"左"行 */
    cnt = numOfModification(r, c, R, c) + dp(r, c+1, R, C);
    if (cnt < dpTable[r][c][R][C])
        dpTable[r][c][R][C] = cnt;

    /* 移除"右"行 */
    cnt = numOfModification(r, C, R, C) + dp(r, c, R, C-1);
    if (cnt < dpTable[r][c][R][C])
        dpTable[r][c][R][C] = cnt;
    
    return dpTable[r][c][R][C];
}

int main () {
    //acceralateIO(0);
    int M, N;
    while (cin >> M >> N) {
        /* 初始化 dp_table */
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < M; k++)
                    for (int l = 0; l < N; l++)
                        dpTable[i][j][k][l] = NotYet;
        
        /* 輸入 */
        int16_t x;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N && cin >> x; j++)
                isOne[i][j] = (x) ? true : false;
        cout << dp(0,0,(M-1),(N-1)) << endl;
    }
    return 0;
}