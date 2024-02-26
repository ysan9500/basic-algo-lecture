#include<bits/stdc++.h>
using namespace std;

int board[502][502]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int n, m;
    cin >> n >> m;
    // int board[n][m] = {0};
    // bool vis[n][m] = {false};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> board[i][j];
    }
    queue<pair<int,int>> Q;
    int pic_num =0;
    int max_breadth = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 || vis[i][j]) continue;
            vis[i][j] = true;
            Q.push({i,j}); int breadth = 0; pic_num++;
            
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop(); breadth++;
                //cout << '(' << cur.first << ',' << cur.second << ") -> \n";
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] == 0) continue;
                    vis[nx][ny] = true;
                    Q.push({nx,ny}); 
                }
            }
            if(breadth > max_breadth) max_breadth = breadth;
        }
    }
    cout << pic_num << '\n' << max_breadth;
    return 0;
}