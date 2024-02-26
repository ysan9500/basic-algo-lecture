#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8][8];
bool watched[8][8];
int cctv;
int min = 64;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void min_update() {

}

void func(int k) {
    if(k == cctv) {
        min_update();
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0 || arr[i][j] == 6) continue;
            if(arr[i][j] == 1) {
                int step = 0;
                for(int a=0; a<4; a++){
                    int nx, ny;
                    do {
                        nx = i + dx[a] * step;
                        ny = j + dy[a] * step;
                        arr[nx][ny] = true;

                    } while(nx < n && ny < m && arr[nx][ny] != 6)
                }
            }
            
        }
    }

}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0 || arr[i][j] == 6) continue; 
            cctv++;
        }
    }

    func(0);
    return 0;
}