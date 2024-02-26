#include <bits/stdc++.h>
using namespace std;

string board[1000];
int dist[1000][1000];
int Jdist[1000][1000];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'F') Q.push({i, j});
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != '.' || dist[nx][ny] > 0) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'J') Q.push({i, j});
            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                if(cur.first == 0 || cur.first == n - 1 || cur.second == 0 || cur.second == m - 1) {
                    cout << Jdist[cur.first][cur.second] + 1;
                    return 0;
                }
                for(int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != '.' || Jdist[nx][ny] > 0 || Jdist[nx][ny] >= dist[nx][ny]) continue;
                    Q.push({nx, ny});
                    Jdist[nx][ny] = Jdist[cur.first][cur.second] + 1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}