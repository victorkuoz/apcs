/* APCS 2016-03-q3 線段覆蓋長度 */
#include <stdio.h>
#include <stdlib.h>

#define max_size 10000000

typedef struct cell {
    short start, end;
} Cell;

int main () {
    int n, min = max_size, max = 0;
    Cell *cells = (Cell*) calloc(max_size, sizeof(Cell));

    scanf("%d", &n);
    for ( int i = 0, s, e; i < n; i++ ) {
        scanf("%d%d", &s, &e);
        cells[s].start++;
        cells[e].end++;
        
        if ( e > max )
            max = e;
        if ( s < min )
            min = s;
    }

    int ans = 0;
    for ( int i = min, covered = 0; i < max; i++ ) {
        covered += cells[i].start;
        covered -= cells[i].end;

        if (covered)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}