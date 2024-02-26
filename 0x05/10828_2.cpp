// http://boj.kr/000e663f39e747d8944794fb277b6f17
#include <bits/stdc++.h>
using namespace std;

int s[10000];
int pos = -1;

void push(int num) {
  s[++pos] = num;
}

void pop(void) {
  if (pos == -1) cout << -1 << '\n';
  else {
    cout << s[pos] << '\n';
    pos--;
  }
}

void size(void) {
  cout << pos + 1 << '\n';
}

void empty(void) {
  if(pos == -1) cout << 1 << '\n';
  else cout << 0 << '\n';
}

void top(void) {
  if(pos == -1) cout << -1 << '\n';
  cout << s[pos] << '\n';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  string cmd;
  int num;
  while(N--) {
    cin >> cmd;
    if(cmd == "push") {
      cin >> num;
      push(num);
    }
    else if(cmd == "pop") pop();
    else if(cmd == "size") size();
    else if(cmd == "empty") empty();
    else if(cmd == "top") top();
  }
  return 0;
}
