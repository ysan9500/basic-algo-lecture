#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> cctv;
int arr[8][8]; // CCTV, wall, empty area.
int dir[8][8]; // direction of each CCTV: 0,1,2,3
bool iswatched[8][8];
int min_area = 64;

void rotate(int x, int y, int r);
int area();
void func(int k);
void watch(int x, int y, int d);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) continue; 
            cctv.push_back({i, j});
        }
    }// 1. get sthe size and elements of array, and count cctv.
    func(0);// 2. get the minimum blind area by rotate() + area().
    cout << min_area;
    return 0;
}

void rotate(int x, int y, int r) {
    dir[x][y] = (dir[x][y] + r) % 4;
} // Gets the coordination of the CCTV and turn it by 90 degrees.

void watch(int x, int y, int d) {
    if(d == 0) {
        for(int j = y; j < m; j++){
            if(arr[x][j] == 6) break;
            iswatched[x][j] = true;
        }
    }
    if(d == 1) {
        for(int i = x; i < n; i++){
            if(arr[i][y] == 6) break;
            iswatched[i][y] = true;
        }
    }
    if(d == 2) {
        for(int j = y; j >= 0; j--){
            if(arr[x][j] == 6) break;
            iswatched[x][j] = true;
        }
    }
    if(d == 3) {
        for(int i = x; i >= 0; i--){
            if(arr[i][y] == 6) break;
            iswatched[i][y] = true;
        }
    }
} // O(N)

int area() {
    for(auto c : cctv) {
        int i = c.first; int j = c.second;
        if(arr[i][j] == 6) iswatched[i][j] = true;
        int d = dir[i][j];
        if(arr[i][j] == 5) {
            watch(i, j, d); watch(i, j, (d+1)%4); watch(i, j, (d+2)%4); watch(i, j, (d+3)%4);
        }
        if(arr[i][j] == 4) {
            watch(i, j, d); watch(i, j, (d+1)%4); watch(i, j, (d+2)%4);
        }
        if(arr[i][j] == 3) {
            watch(i, j, d); watch(i, j, (d+1)%4);
        }
        if(arr[i][j] == 2) {
            watch(i, j, d); watch(i, j, (d+2)%4);
        }
        if(arr[i][j] == 1) {
            watch(i, j, d);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!iswatched[i][j]) cnt++;
            iswatched[i][j] = false;
        }
    }
    return cnt;
} // Calculates the area of blind spot in current configuration.  O(N^3)

void func(int k) {
    if(k == cctv.size()) {
        int val = area();
        if(val < min_area) min_area = val;
        return;
    }
    int skip = k;
    for(auto c : cctv) {
        if(skip > 0) {
            skip--;
            continue;
        }
        int i = c.first; int j = c.second;
        func(k + 1);
        if(arr[i][j] == 5) continue;
        rotate(i, j, 1);
        func(k + 1);
        if(arr[i][j] == 2) {
            rotate(i, j, -1);
            continue;
        }
        rotate(i, j, 1);
        func(k + 1);
        rotate(i, j, 1);
        func(k + 1);
        rotate(i, j, -3);
    } // If encounter cctv, skip k cctv and rotate, run func(k+1).
}
// 처음에 cctv개수를 셀 때 개수만 셀 게 아니라 좌표까지 저장하면 cctv 위치를 찾는 N^2의 시간을 아낄 수 있음.


/*
void func(int k) {
    if(k == cctv.size()) {
        int val = area();
        if(val < min_area) min_area = val;
        return;
    }
    int skip = k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0 || arr[i][j] == 6) continue;
            if(skip > 0) {
                skip--;
                continue;
            }
            func(k + 1);
            if(arr[i][j] == 5) continue;
            rotate(i, j);
            func(k + 1);
            if(arr[i][j] == 2) {
                rotate(i, j); rotate(i, j); rotate(i, j);
                continue;
            }
            rotate(i, j);
            func(k + 1);
            rotate(i, j);
            func(k + 1);
            rotate(i, j);
        }
    } // If encounter cctv, skip k cctv and rotate, run func(k+1).
} */
