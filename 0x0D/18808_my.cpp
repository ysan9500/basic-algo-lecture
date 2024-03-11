#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int rot = 0;
bool sticker[10][10];
bool laptop[40][40];
int area = 0;

void get_sticker();
void put_sticker();
bool isoverlap(int x, int y);
void paste(int x, int y);
void rotate_sticker();

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < k; k++){
        cin >> r >> c;
        get_sticker();
        put_sticker();
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(laptop[i][j]) area++;
        }
    }

    cout << area;

    return 0;
}

void get_sticker(){
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++){
            cin >> sticker[i][j];
        }
    }
}

void put_sticker(){
    if(rot == 4) {
        rot = 0;
        return;
    }

    for(int i = 0; i + r <= n; i++){
        for(int j = 0; j + c <= m; j++){
            if(isoverlap(i, j)) continue;
            paste(i, j);
            return;
        }
    }
    rotate_sticker(); rot++;
    put_sticker();
    return;
}

bool isoverlap(int x, int y){
    for(int i = x; i < x+r; i++){
        for(int j = y; j < y+c; j++){
            if(sticker[i][j] == 1 && laptop[i][j] == 1) return true;
        }
    }
    return false;
}

void paste(int x, int y){
    for(int i = x; i < x+r; i++){
        for(int j = y; j < y+c; j++){
            laptop[i][j] = sticker[i-x][j-y];
        }
    }
}

void rotate_sticker(){
    bool temp[10][10];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            temp[i][j] = sticker[j][c-i];
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            sticker[i][j] = temp[i][j];
        }
    }
    return;
}