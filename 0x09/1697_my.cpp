#include <bits/stdc++.h>
using namespace std;

int dist[100005];
int n, k;

int main() {
    cin >> n >> k;
    for(int i = 0; i < 100005; i++) dist[i] = -1;
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << '\n';
        if(cur == k) {
            cout << dist[cur];
            return 0;
        }
        if(cur < 0 || cur > 100000) continue;
        if(dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1;
            Q.push(cur - 1);
        }
        if(dist[cur + 1] == -1) {
            dist[cur + 1] = dist[cur] + 1;
            Q.push(cur + 1);
        }
        if(2*cur > 100000) continue;
        if(dist[2 * cur] = -1) {
            dist[2 * cur] = dist[cur] + 1;
            Q.push(2 * cur);
        }
    }
    cout << dist[k];
}