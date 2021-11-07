/* APCS 2020-01-q4 自動分裝 */
#include <iostream>
#include <vector>

using namespace std;

#define acceralateIO(x) ios::sync_with_stdio(x); cin.tie(x); cout.tie(x);

/* 定義節點結構 */
struct Node {
    int W = 0, L = 0, R = 0;
};

int N, M;
vector<Node> nodes;

/* 針對非葉節點，遞迴計算子樹累積之重量 */
int initialize(int idx) {
    if (0 < idx && idx < N)
        nodes.at(idx).W = initialize(nodes.at(idx).L) + initialize(nodes.at(idx).R);
    return nodes.at(idx).W;
}

/* 遞迴插入物品直到葉節點 */
void insert(int idx, int w) {
    nodes.at(idx).W += w;
    int l = nodes.at(idx).L, r = nodes.at(idx).R;
    if (l < 1 && r < 1)
        cout << idx;
    else if (nodes.at(l).W <= nodes.at(r).W)
        insert(l, w);
    else
        insert(r, w);
}

int main () {
    acceralateIO(0);
    cin >> N >> M;
    nodes.resize(2*N);

    /* 輸入所有箱子之初始重量 (N ~ 2N-1) */
    for (int i = N, size = (2*N); i < size; i++)
        cin >> nodes.at(i).W;
    
    /* 按順序輸入欲放入之物品重量 */
    vector<int> inputs(M);
    for (int i = 0; i < M; i++)
        cin >> inputs.at(i);
    
    /* 輸入樹狀圖，用陣列搭配索引值紀錄 */
    for (int p, i = 0, size = (N-1); i < size && cin >> p; i++)
        cin >> nodes.at(p).L >> nodes.at(p).R;

    /* 初始化所有切換器之累積重量 */
    initialize(1);

    /* 按順序放入物品並印出結果 */
    for (int j = 0; j < M; j++) {
        insert(1, inputs.at(j));
        if (j != (M-1))
            cout << " ";
        else
            cout << "\n";
    }
    return 0;
}