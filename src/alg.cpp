// Copyright 2021 NNTU-CS
int binar(int *arr, int l, int r, int a) {
    int left = l, right = r, mid = 0; bool f = 0;
    while (left <= right)  {
        mid = (left + right) / 2;
        if (arr[mid] == a) {
            return binar(arr, l, mid - 1, a) + binar(arr, mid + 1, r, a) + 1;
        }
        if (a < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int countPairs1(int *arr, int len, int value) {
  int count1 = 0;
  for (int i = 0; i < len; i++) {
    for (int k = 0; k < len; k++) {
      if ((i != k) && (arr[i] + arr[k] == value)) {
        count1 += 1;
      }
    }
  }
  return count1 / 2;
}

int countPairs2(int *arr, int len, int value) {
  int count2 = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int k = len - 1; k > i; k--) {
      if (arr[i] + arr[k] == value) {
        count2 += 1;
      }
    }
  }
  return count2;
}

int countPairs3(int *arr, int len, int value) {
  int count3 = 0;
  for (int i = 0; i < len; i++) {
      count3 += binar(&arr[i + 1], 0, len - i, value - arr[i]);
  }
  return count3;
}
