#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[20];
int sum, cnt;

void func(int k) {
    if(k == n) {
        if(sum == s) cnt++;
        return;
    }
    func(k+1);
    sum += arr[k];
    func(k+1);
    sum -= arr[k];
}

int main() {
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    func(0);
    if(s == 0) cnt--;
    cout << cnt;
    return 0;
}