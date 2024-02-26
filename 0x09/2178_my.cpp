#include <bits/stdc++.h>
using namespace std;

string maze[100];
int path[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

int main(void) {
    cin >> N >> M;
    int row;
    for(int i = 0; i < N; i++) {
        cin >> maze[i];
    }
    queue<pair<int,int>> Q;
    Q.push({0,0});
    path[0][0] = 1;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(maze[nx][ny] == '0' || path[nx][ny] > 0) continue;
            Q.push({nx, ny}); path[nx][ny] = path[cur.first][cur.second] + 1;
        }
    }
    cout << path[N - 1][M -1];
    return 0;
}