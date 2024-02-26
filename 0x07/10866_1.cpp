// http://boj.kr/82805c43b7ff48adb21a37403d55f736
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> dq;
  int N;
  cin >> N;
  string cmd;
  int num;

  while(N--) {
    cin >> cmd;
    if(cmd == "push_front") {
      cin >> num;
      dq.push_front(num);
    }
    else if(cmd == "push_back") {
      cin >> num;
      dq.push_back(num);
    }
    else if(cmd == "pop_front") {
      if(dq.empty()) cout << -1;
      else {
        cout << dq.front();
        dq.pop_front();
      }
      cout << '\n';
    }
    else if(cmd == "pop_back") {
      if(dq.empty()) cout << -1;
      else {
        cout << dq.back();
        dq.pop_back();
      }
      cout << '\n';
    }
    else if(cmd == "size") {
      cout << dq.size() << '\n';
    }
    else if(cmd == "empty") {
      cout << (int)dq.empty() << '\n';
    }
    else if(cmd == "front") {
      if(dq.empty()) cout << -1;
      else {
        cout << dq.front();
      }
      cout << '\n';
    }
    else if(cmd == "back") {
      if(dq.empty()) cout << -1;
      else {
        cout << dq.back();
      }
      cout << '\n';
    }
  }
}
