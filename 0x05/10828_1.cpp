// http://boj.kr/c792146f735b42559e8cb3bf21e61fa9
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> stack;
  int N;
  cin >> N;
  string cmd;
  int num;
  while(N--) {
    cin >> cmd;
    if(cmd == "push") {
      cin >> num;
      stack.push(num);
    }
    else if(cmd == "pop") {
      if(stack.empty()) cout << -1 << '\n';
      else {
        cout << stack.top() << '\n';
        stack.pop();  
      }
    }
    else if(cmd == "size") cout << stack.size() << '\n';
    else if(cmd == "empty") cout << (int)stack.empty() << '\n';
    else if(cmd == "top") {
      if(stack.empty()) cout << -1 << '\n';
      else cout << stack.top() << '\n';
    }
  }
  return 0;
}
