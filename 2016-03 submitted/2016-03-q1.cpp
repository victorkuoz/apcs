/* APCS 2016-03-q1 成績指標 */
#include <stdio.h>
#include <algorithm>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    int arr[n], min = 101, max = (-1);
    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &arr[i]);
        if ( arr[i] < 60 ) {
            if ( arr[i] > max )
                max = arr[i];
        }
        else {
            if ( arr[i] < min )
                min = arr[i];
        }
    }

    sort(arr, arr+n);
    for ( int i = 0; i < n; i++ )
        printf("%d%c", arr[i], (i!=(n-1)) ? ' ' : '\n');
    if ( max == (-1) )
        printf("best case\n");
    else
        printf("%d\n", max);

    if ( min == 101 )
        printf("worst case\n");
    else
        printf("%d\n", min);

    return 0;
}