// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
int count = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value) {
count += 1;
}
}
}
return count;
}
int countPairs2(int* arr, int len, int value) {
int count = 0;
int temp = 0;
for (int i = 0; i < len; i++) {
for (int j = len; j > i; j--) {
if (arr[i] + arr[j] == value) {
count += 1;
}
}
}
return count;
}
int countPairs3(int* arr, int len, int value) {
int count = 0, mid = 0, left = 0, right = 0;
bool tf = true;
for (int i = 0; i < len - 1; i++) {
if (value > arr[i]) {
left = i + 1;
right = len;
while (tf) {
mid = (left + right) / 2;
if (value - arr[i] < arr[mid]) {
right = mid - 1;
}
else if (value - arr[i] > arr[mid]) {
left = mid + 1;
}
else {
count += 1;
for (int k = 1; k < len; k++) {
if (arr[mid + k] == arr[mid]) {
count += 1;
}
else {
break;
}
}
for (int k = 1; k < len - mid; k++) {
if (arr[mid - k] == arr[mid]) {
count += 1;
}
else {
break;
}
}
tf = false;
}
if (left > right) {
tf = false;
}
}
tf = true;
}
}
return count;
}
