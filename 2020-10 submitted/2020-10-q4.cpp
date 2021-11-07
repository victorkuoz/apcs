/* APCS 2020-10-q4 低地距離 */
#include <vector>
#include <iostream>
using namespace std;
#define accelerateIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int x, n, N;
vector<int> BIT(0);

void modify (int pos){
	while (pos < N) {
		BIT[pos]++;
		pos += (pos & (-pos));
	}
}

int query (int pos) {
	int sum = 0;
	while (pos) {
		sum += BIT[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}

int main(){
    /* 加速讀寫 */
    accelerateIO

	cin >> n;
    N = (2*n);

    BIT.resize(N);
    vector<int> arr(N);
    vector<int> pos(n+1, (-1));

	uint64_t ans = 0;
    for (int i = 0; i < N && cin >> x; i++) {
        arr.at(i) = query(x-1);
        if (pos.at(x) < 0)
            pos.at(x) = i;
        else
            ans += arr.at(i) - arr.at(pos.at(x));
        modify(x);
    }
	cout << ans << endl;
    return 0;
}