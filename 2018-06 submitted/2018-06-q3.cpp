/* APCS 2018-06-q3 工作排程 */
#include <iostream>
#include <climits>
#include <vector>
#include <deque>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, P;
    cin >> N >> M;

    /* 利用 deque 儲存各個工作的資料 */
    vector<deque<pair<int, int> > > jobs(M, deque<pair<int, int> >(0));

    int m, t;
    for (int i = 0; i < M && cin >> P; i++)
        for (int j = 0; j < P && cin >> m >> t; j++)
            jobs.at(i).push_back(make_pair(m,t));
    
    vector<int> ready_time(M,0);
    vector<int> avail_time(N,0);

    int tmp, min, cnt = 0, ans = 0, TODO;

    while (cnt < M) {
        min = INT_MAX;
        for (int i = 0, size = jobs.size(); i < size; i++) {
            tmp = max(avail_time.at(jobs.at(i).front().first), ready_time.at(i)) +
                  (jobs.at(i).front().second);
            if (tmp < min) {
                min = tmp;
                TODO = i;
            }
        }

        avail_time.at(jobs.at(TODO).front().first) = ready_time.at(TODO) = min;
        jobs.at(TODO).pop_front();

        if (jobs.at(TODO).size() < 1) {
            jobs.erase(jobs.begin()+TODO);
            ready_time.erase(ready_time.begin()+TODO);
            ans += min;
            cnt++;
        }
    }

    cout << ans << endl;

    return 0;
}