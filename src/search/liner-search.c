#include <stdio.h>

#define TARGET 8

int main() {
  int ary[10] = {
    0,1,2,3,4,5,6,7,8,9
  };

  int count = sizeof(ary)/sizeof(int);

  for (int i = 0; i < count; i++) {
    if (TARGET == ary[i]) {
      printf("check!");
      return 0;
    }
  }
  return 1;
}
