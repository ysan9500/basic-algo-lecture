// http://boj.kr/ece8236c02cf46aba9933f28e358b51c
#include <bits/stdc++.h>
using namespace std;

/*
int main(void) {
  char word[101];

  cin >> word;
  for(char i = 'a'; i <= 'z'; i++){
    int count = 0;
    for(int j = 0; j < strlen(word); j++){
      if(i == word[j]){
        count++;
      }
    }
    cout << count << " ";
  }
  return 0;
}
*/

int main(void) {
  string s;
  cin >> s;
  int count[26] = {0};
  for(auto c : s) {
    count[c - 'a']++;
  }
  for(int i = 0; i < 26; i++) {
    cout << count[i] << ' ';
  }
  return 0;
}