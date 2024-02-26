#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  queue<int> q;
  string cmd;
  int N;
  cin >> N;
  int num;

  while(N--) {
    cin >> cmd;
    if(cmd == "push") {
      cin >> num;
      q.push(num);
    }
    else if(cmd == "pop") {
      if(q.empty()) cout << -1;
      else {
      cout << q.front();
      q.pop();
      }
      cout << '\n';
    }
    else if(cmd == "size") cout << q.size() << '\n';
    else if(cmd == "empty") cout << (int)q.empty() << '\n';
    else if(cmd == "front") {
      if(q.empty()) cout << -1 <<'\n';
      else cout << q.front() << '\n';
    }
    else if(cmd == "back") {
      if(q.empty()) cout << -1;
      else cout << q.back() << '\n';
    }
  }   
}