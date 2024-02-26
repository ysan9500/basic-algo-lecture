// http://boj.kr/84654f16875542e6a84d3da7e4cf0dac
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  list<char> word;
  string initword;
  cin >> initword;
  for(char c : initword) {
    word.push_back(c);
  }
  auto cursor = word.end(); //Returns an iterator referring to the past-the-end element in the list container.
  int M;
  cin >> M;
  while(M--) {
    char cmd;
    cin >> cmd;
    if(cmd == 'P') {
      char c;
      cin >> c;
      word.insert(cursor, c);
    }
    else if(cmd == 'L') {
      if(cursor != word.begin()) cursor--;
    }
    else if(cmd == 'D') {
      if(cursor != word.end()) cursor++;
    }
    else if(cmd == 'B') {
      if(cursor != word.begin()) {
        cursor--;
        cursor = word.erase(cursor);
      }
    }
    /*
    cout << "output: ";
    for(auto i : word) cout  << i;
    cout << " cursor: " << *cursor;
    cout << '\n';
    */
  }
  for(auto i : word) cout << i;
  return 0;
}
