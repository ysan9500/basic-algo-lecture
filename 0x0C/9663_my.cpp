#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool isused1[15], isused2[29], isused3[29];

void func(int k) {
    if(n == k) {
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(isused1[i] || isused2[k + i] || isused3[n - 1 + k - i]) continue;
        isused1[i] = true;
        isused2[k + i] = true;
        isused3[n - 1 + k - i] = true;
        func(k + 1);
        isused1[i] = false;
        isused2[k + i] = false;
        isused3[n - 1 + k - i] = false;
    }


}

int main() {
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}