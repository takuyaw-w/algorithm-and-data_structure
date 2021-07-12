#include <stdio.h>

#define TARGET 8

int main(void) {
  int ary[10] = {
    1,2,3,4,5,6,7,8,9,10
  };

  int count = sizeof(ary) / sizeof(int);
  int min = 0;
  int max = count - 1;
  int mid;

  while (min <= max) {
    mid = ( min + max ) / 2;

    if (ary[mid] == TARGET) {
      printf("check!\n");
      return 0;
    } else if (ary[mid] < TARGET) {
      min = mid + 1;
    } else if (ary[mid] > TARGET) {
      max = mid - 1;
    }
  }

  printf("no check");
  return 1;
}
