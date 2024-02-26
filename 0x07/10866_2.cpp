// http://boj.kr/753be6ff423e480895c95667550b81c0
#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int dat[2*MX + 1];
int head = MX, tail = MX;

void push_front(int num) {
  dat[--head] = num;
}

void push_back(int num) {
  dat[tail++] = num;
}

int pop_front(void) {
  if(head == tail) return -1;
  else return dat[head++];
}

int pop_back(void) {
  if(head == tail) return -1;
  else return dat[--tail];
}

int size(void) {
  return tail - head;
}

bool empty(void) {
  return tail==head;
}

int front(void) {
  if(head == tail) return -1;
  else return dat[head];
}

int back(void) {
  if(head == tail) return -1;
  else return dat[tail - 1];
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
    if(cmd == "push_front") {
      cin >> num;
      push_front(num);
    }
    else if(cmd == "push_back") {
      cin >> num;
      push_back(num);
    }
    else if(cmd == "pop_front") {
      cout << pop_front() << '\n';
    }
    else if(cmd == "pop_back") {
      cout << pop_back() << '\n';
    }
    else if(cmd == "size") {
      cout << size() << '\n';
    }
    else if(cmd == "empty") {
      cout << (int)empty() << '\n';
    }
    else if(cmd == "front") {
      cout << front() << '\n';
    }
    else if(cmd == "back") {
      cout << back() << '\n';
    }
  }
  return 0;
}
