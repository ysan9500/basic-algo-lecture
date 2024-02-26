// http://boj.kr/bfa34c5aa15d49e1878dc3e79cc0facb
#include <bits/stdc++.h>
using namespace std;

int q[10005];
int head, tail = 0;

void push(int num) {
  q[tail++] = num;
}

int pop(void) {
  return q[head++];
}

int size(void) {
  return tail - head; 
}

bool empty(void) {
  return tail == head;
}

int front(void) {
  return q[head];
}

int back(void) {
  return q[tail];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

    string cmd;
  int N;
  cin >> N;
  int num;

  while(N--) {
    cin >> cmd;
    if(cmd == "push") {
      cin >> num;
      push(num);
    }
    else if(cmd == "pop") {
      if(empty()) cout << -1;
      else {
      cout << pop();
      }
      cout << '\n';
    }
    else if(cmd == "size") cout << size() << '\n';
    else if(cmd == "empty") cout << (int)empty() << '\n';
    else if(cmd == "front") {
      if(empty()) cout << -1 << '\n';
      else cout << front() << '\n';
    }
    else if(cmd == "back") {
      if(empty()) cout << -1 << '\n';
      else cout << back() << '\n';
    }
  }   
}
