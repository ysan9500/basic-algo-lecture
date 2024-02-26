#include <bits/stdc++.h>
using namespace std;

int box[1000][1000];
int days[1000][1000];
int m, n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> box[i][j];
        }
    }

    queue<pair<int,int>> Q;
    int min_days = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(box[i][j] != 1 || days[i][j] != 0) continue;
            
            Q.push({i, j});
            int min_days_local = 0;

            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(box[nx][ny] != 0 || days[nx][ny] != 0) continue;
                    Q.push({nx, ny});
                    box[nx][ny] = 1;
                    days[nx][ny] = days[cur.first][cur.second] + 1;
                    if(days[nx][ny] > min_days_local) min_days_local = days[nx][ny];
                }
            }
            if(min_days_local > min_days) min_days = min_days_local;
        }
    }

    cout << min_days;

    return 0;
}