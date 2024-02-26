int func2(int arr[], int N) {
  int count[101] = {0};
  for(int i = 0; i < N; i++) {
    if(count[100 - arr[i]] > 0) {
      return 1;
    }
    else {
      count[arr[i]]++;
    }
  }
  return 0;
}