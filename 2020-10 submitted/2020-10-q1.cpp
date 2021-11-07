/* APCS 2020-10-q1 人力分配 */
#include <iostream>
using namespace std;

#define profit(x) (a*(x)*(x) + b*(x) + c)
/* (1) N  = X1 + X2
   (2) Y1 = A1*(X1)^2 + B1*(X1) + C1
   (3) Y2 = A2*(X2)^2 + B2*(X2) + C2

   (4) X2 = N - X1
   (5) Y1 + Y2 = [A1*(X1)^2 + B1*(X1) + C1] + [A2*(N-X1)^2 + B2*(N-X1) + C2]

   (6) Y1 + Y2 = (A1 + A2)*(X1)^2 + (B1 - B2 - 2*A2*N)*(X1) + (C1 + C2 + A2*(N)^2 + B2*N) */

int main () {
    int A1, B1, C1, A2, B2, C2, N;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2 >> N;
    int a = (A1 + A2), b = (B1 - B2 - 2*A2*N), c = (C1 + C2 + A2*N*N + B2*N);
    
    int tmp, ans = profit(0);
    if ((tmp = profit(N)) > ans)
        ans = tmp;

    int vertex = (-b)/(2*a);
    if (0 <= vertex && vertex <= N) 
        if ((tmp = profit(vertex)) > ans)
            ans = tmp;
    if (0 <= (vertex-1) && (vertex-1) <= N)
        if ((tmp = profit(vertex-1)) > ans)
            ans = tmp;
    if (0 <= (vertex+1) && (vertex+1) <= N)
        if ((tmp = profit(vertex+1)) > ans)
            ans = tmp;
    cout << ans << endl;
    return 0;
}