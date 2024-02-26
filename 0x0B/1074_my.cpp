#include <bits/stdc++.h>
using namespace std;

int travel(int n, int r, int c) {
    if(n == 1) return 2 * r + c;
    int half = pow(2, n-1);
    return (2 * (r/half) + c/half) * pow(half, 2) + travel(n-1, r%half, c%half);
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    cout << travel(n, r, c);
    return 0;
}