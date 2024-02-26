#include <bits/stdc++.h>
using namespace std;

int box[1000][1000];
int days[1000][1000];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> m >> n;
    queue<pair<int,int>> Q;
 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) Q.push({i,j});
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(box[nx][ny] != 0 || days[nx][ny] != 0) continue;
            Q.push({nx, ny});
            box[nx][ny] = 1;
            days[nx][ny] = days[cur.first][cur.second] + 1;
        }
    }

    int min_days = 0;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(box[i][j] == 0) {
                cout << -1;
                return 0;
            }
            min_days = max(min_days, days[i][j]);
        }
    }

    cout << min_days;
    return 0;
}

