/* APCS 2018-06-p4 反序數量 */
#include <bits/stdc++.h>

using namespace std;

vector<int> data(0);

/* 計算區間含 begin 但不含 end */
unsigned long long  divide_and_conquer (int begin, int end) {
    /* 終止條件 : 區間長度小於3 */
    if (end - begin < 3) {
        if (end - begin < 2)
            return 0;
        if (data.at(begin) > data.at(end-1))
            return 1;
        return 0;
    }
    
    /* 遞迴計算左右子樹的反序數量 */
    int mid = (begin + end)/2;
    unsigned long long sum = divide_and_conquer(begin, mid) +
                             divide_and_conquer(mid, end);

    /* 分別排序左右子樹 */
    sort(data.begin()+begin, data.begin()+mid);
    sort(data.begin()+mid, data.begin()+end);

    /* 計算跨越中點的反序數量 */
    for (int l = begin, r = mid; (l < mid) && (r < end); r++) {
        while ( l < mid && data.at(l) <= data.at(r))
            l++;
        sum += (mid - l);
    }

    return sum;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    data.resize(n);
    for (int i = 0; i < n; i++)
        cin >> data.at(i);

    cout << divide_and_conquer(0, n) << endl;

    return 0;
}