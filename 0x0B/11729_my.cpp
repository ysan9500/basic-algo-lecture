#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int a, int b) {
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    int c = 6 - a - b;
    hanoi(n-1, a, c); cout << a << ' ' << b << '\n'; hanoi(n-1, c, b);
}

int main() {
    int n;
    cin >> n;
    cout << (1<<n) - 1 << '\n';
    hanoi(n, 1, 3);
    return 0;
}