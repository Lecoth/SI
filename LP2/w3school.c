#include <stdio.h>

void count() {
  int myNum = 0; // Keeps its value between calls
  myNum++;
  printf("num = %d\n", myNum);
}

int main() {
  count();
  count();
  count();
  return 0;
}