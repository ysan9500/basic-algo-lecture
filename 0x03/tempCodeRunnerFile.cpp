#include <bits/stdc++.h>
using namespace std;

int main(void) {
  char word[100];

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